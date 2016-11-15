/*************************************************************************
> File Name: Student_Management_System.c
> Author: yangfan
> Mail:imqqyangfan@gmail.com 
> Created Time: 2016年04月27日 星期三 00时08分22秒
************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void Stu_Login();
void Stu_Main();
void Stu_Memu();
void Input_Student();
void Find_Student_Name();
void Find_Student_Number();
void Find_Student_QQ_Number();
void Find_Student_Tel();
void Delete_Student();
void Look_Student_List();
void Mod_Student();
char *Mod_Scan(char arr[]);
void Stu_Mod_Printf(struct student *stu);
void stu_print(struct student *stu);
void Return_Menu();
struct student File_Student_Creat(struct student *pHead);

void Return_Menu(){
    int i ;
    printf("\n\n\t\t\t\t\t是否返回主菜单?(1/0):");
    scanf("%d",&i);
    if( i == 1) Stu_Memu();
    else exit(1);
}

// ------------------------------------------------无耻分割线----------------------------------------------------------------
typedef struct student{
    char Stu_Name[10];
    char Stu_Number[10];
    char Stu_Sex[5];
    char Stu_Tel[12];
    char Stu_QQ_Number[11];

    struct student *next;
}STU;
//----------------------------------------文件中读取学生信息并且存入链表-------------------------------------------------------
struct student *File_Student_Creat(){
    FILE *fp;
    struct student *pHead = NULL;
    int count = 0;
    struct student *pNew,*pEnd;
    fp = fopen("student.txt","r+");
    fseek(fp,0,SEEK_SET);
    pNew = pEnd = (STU *)malloc(sizeof(STU));
    while(fread(pNew,sizeof(STU),1,fp)){
        if(count == 0){
            pNew->next = pHead;
            pEnd = pNew;
            pHead = pNew;
        }
        else{
            pNew->next = NULL;
            pEnd->next = pNew;
            pEnd = pNew;
        }
        pNew = (STU *)malloc(sizeof(STU));
    }
    free(pNew);
    fclose(fp);
    return pHead;
}
//--------------------------------------------------修改学生信息----------------------------------------
void Mod_Student(){
    STU *stu,*pHead;
    stu = pHead = File_Student_Creat();
    char Temp_Name[10];
    int i;
    printf("\n\t\t\t\t\t输入你要修改的学生姓名:");
    scanf("%s",Temp_Name);
    while(stu != NULL){
        if(strcmp(stu->Stu_Name,Temp_Name) == 0){
            system("clear");
            printf("\n\t\t\t\t\t以下是这个学生的各项信息:");
            stu_print(stu);
            Stu_Mod_Printf(stu);
            printf("\n\n\t\t\t\t\t是否确认当前修改?(1/0)");
            scanf("%d",&i);
            if(i == 1){
                FILE *fp;
                fp = fopen("student.txt","w+");
                while(pHead != NULL){
                    fwrite(pHead,sizeof(STU),1,fp);
                    pHead = pHead->next;
                }
                fclose(fp);
                printf("\n\n\t\t\t\t\t修改成功!");
                break;
            }
            else break;
        }
        stu = stu->next;
    }
    Return_Menu();
}
void Stu_Mod_Printf(struct student *stu){
    int i;
    printf("\n\t\t\t\t\t\t请选择你要修改的信息");
    printf("\n\t\t\t\t\t\t1:姓名");
    printf("\n\t\t\t\t\t\t2:学号");
    printf("\n\t\t\t\t\t\t3:性别");
    printf("\n\t\t\t\t\t\t4:电话");
    printf("\n\t\t\t\t\t\t5:QQ号");
    printf("\n\t\t\t\t\t\t6:返回\n\n\t\t\t\t\t");
    scanf("%d",&i);
    switch(i){
        case 1:strcpy(stu->Stu_Name,Mod_Scan(stu->Stu_Name));break;
        case 2:strcpy(stu->Stu_Number,Mod_Scan(stu->Stu_Number));break;
        case 3:strcpy(stu->Stu_Sex,Mod_Scan(stu->Stu_Sex));break;
        case 4:strcpy(stu->Stu_Tel,Mod_Scan(stu->Stu_Tel));break;
        case 5:strcpy(stu->Stu_QQ_Number,Mod_Scan(stu->Stu_QQ_Number));break;
        case 6:return;break;
    }
}

char *Mod_Scan(char *arr){
    char Temp[20];
    printf("\n\n\t\t\t\t\t原信息:%s",arr);
    printf("\n\n\t\t\t\t\t请输入新的信息:");
    scanf("%s",Temp);
    arr = Temp;
    return arr;
}
//---------------------------------------------以列表打印所有学生信息-----------------------
void Look_Student_List(){
    system("clear");
    STU *stu;
    int count = 1;
    stu = File_Student_Creat();
    if(stu == NULL) {printf("\n\n\t\t\t列表里没有学生！");   Stu_Memu(); }
    else{
        printf("\n\n\n");
        printf("\t\t\t\t|————————————————————————————————————————————————————————————————————————————————————|\n");
        printf("\t\t\t\t| 序号       学号            姓名         性别          电话              QQ号       |\n");
        printf("\t\t\t\t|————————————————————————————————————————————————————————————————————————————————————|\n");
        while(stu != NULL){
            printf("\t\t\t\t|%4d%16s%16s%10s%16s%16s\t     |\n",count,stu->Stu_Number,stu->Stu_Name,stu->Stu_Sex,stu->Stu_Tel,stu->Stu_QQ_Number);
            printf("\t\t\t\t|————————————————————————————————————————————————————————————————————————————————————|\n");
            stu = stu->next;
            count++;
        }
        Return_Menu();
    }
}
//-------------------------------------------------打印学生信息--------------------------------------------------------------------
void stu_print(STU *stu){
    printf("\n\n\t\t\t\t\t学生姓名:%s",stu->Stu_Name);     
    printf("\n\t\t\t\t\t学生学号:%s",stu->Stu_Number);
    printf("\n\t\t\t\t\t学生性别:%s",stu->Stu_Sex);
    printf("\n\t\t\t\t\t学生电话:%s",stu->Stu_Tel);
    printf("\n\t\t\t\t\t学生QQ号:%s",stu->Stu_QQ_Number);
}
//--------------------------------------------------删除学生--------------------------------------------------------------------
void Delete_Student(){
    struct student *stu,*pHead;
    char Temp_Name[10];
    printf("\n\n\t\t\t请输入你想要删除的学生姓名\n\n\t\t姓名:");
    scanf("%s",Temp_Name);
    pHead = stu = File_Student_Creat();
    if(strcmp(stu->Stu_Name,Temp_Name) == 0) {
        stu_print(stu);
        printf("\n\n\n\t\t\t确认删除？\t");
        int i;
        scanf("%d",&i);
        if(i != 1){
            printf("\n\n\t\t\t取消操作");
            Return_Menu();
        }
        pHead = stu->next;
        FILE *fp;
        fp = fopen("student.txt","w+");
        while(pHead != NULL){
            fwrite(pHead,sizeof(STU),1,fp);
            pHead = pHead->next;
        }
        fclose(fp);
        printf("\n\n\t\t\t删除成功！");
        Return_Menu();
    }
    while(stu->next != NULL){
        if(strcmp(stu->next->Stu_Name,Temp_Name) == 0){
            stu_print(stu->next);
            printf("\n\n\n\t\t\t确认删除？\t");
            int Pcontinue;
            scanf("%d",&Pcontinue);
            if(Pcontinue == 1) {
                if(stu->next->next == NULL) stu->next = NULL;
                else stu->next = stu->next->next;
                FILE *fp;
                fp = fopen("student.txt","w+");
                while(pHead != NULL){
                    fwrite(pHead,sizeof(STU),1,fp);
                    pHead = pHead->next;
                }
                fclose(fp);
                printf("\n\n\t\t\t删除成功！");
                Return_Menu();
            }
            else{
                printf("\n\n\t\t\t取消操作");
                Return_Menu();
            }
        }
        stu = stu->next;
    }
    printf("\n\n\n\t\t\t列表中没有找到这个学生！");
    free(pHead);
    Return_Menu();
}
//------------------------------------------------学生信息输入-----------------------------------------------------------------
void Input_Student(){
    int iCount = 1;
    FILE *fp;
    if((fp = fopen("student.txt","at+")) == NULL){
        printf("Open file faild!");
        exit(1);
    }
    system("clear");
    STU *pHead = NULL;
    STU *pEnd,*pNew;
    int boolom;
    pNew = pEnd = (STU *)malloc(sizeof(STU));
    printf("\n\t\t\t输入学生信息\n");
    printf("\n\t\t学号:");
    scanf("%s",pNew->Stu_Number);
    printf("\n\t\t姓名:");
    scanf("%s",pNew->Stu_Name);
    printf("\n\t\t性别:");
    scanf("%s",pNew->Stu_Sex);
    printf("\n\t\t电话:");
    scanf("%s",pNew->Stu_Tel);
    printf("\n\t\tQQ号:");
    scanf("%s",pNew->Stu_QQ_Number);
    fwrite(pNew,sizeof(STU),1,fp);
    printf("\n\t\t是否继续输入？(1/0)");
    scanf("%d",&boolom);
    while(boolom == 1){
        if(iCount = 1){
            pNew->next = pHead;
            pEnd = pNew;
            pHead = pNew;
        }
        else{
            pNew->next = NULL;
            pEnd->next = pNew;
            pEnd = pNew;
        }
        iCount++;
        system("clear");
        printf("\n\t\t\t输入学生信息\n");
        pNew = (STU *)malloc(sizeof(STU));
        printf("\n\t\t学号:");
        scanf("%s",pNew->Stu_Number);
        printf("\n\t\t姓名:");
        scanf("%s",pNew->Stu_Name);
        printf("\n\t\t性别:");
        scanf("%s",pNew->Stu_Sex);
        printf("\n\t\t电话:");
        scanf("%s",pNew->Stu_Tel);
        printf("\n\t\tQQ号:");
        scanf("%s",pNew->Stu_QQ_Number);
        fwrite(pNew,sizeof(STU),1,fp);
        printf("\n\t\t是否继续输入(1/0)");
        scanf("%d",&boolom);
    }
    fclose(fp);
    free(pNew);
    Return_Menu();
}
//-----------------------------------------------------用户查找--------------------------------------------------------------

void Find_Student(){
    system("clear");
    int choose;
    printf("\n\t\t\t请选择查找方式\n");
    printf("\n\t\tNo1:姓名\n");
    printf("\n\t\tNo2:学号\n");
    printf("\n\t\tNo3:电话\n");
    printf("\n\t\tNo4:QQ号\n");
    printf("\n\t\tNo5:返回主菜单\n");
    scanf("%d",&choose);
    switch(choose){
        case 1:Find_Student_Name();break;
        case 2:Find_Student_Number();break;
        case 3:Find_Student_Tel();break;
        case 4:Find_Student_QQ_Number();break;
        case 5:Stu_Memu();break;
    }
}
//根据QQ查找
void Find_Student_QQ_Number(){
    struct student *stu;
    char Temp_QQ_Number[10];
    printf("\n\n\t\t\t请输入QQ\n\n\t\tQQ:");
    stu = File_Student_Creat();
    scanf("%s",Temp_QQ_Number);
    while(stu != NULL){
        if(strcmp(stu->Stu_QQ_Number,Temp_QQ_Number) == 0){
            system("clear");
            printf("\n\n\t\t\t已找到！");
            stu_print(stu);
            Return_Menu();
        }
        stu = stu->next;
    }
    printf("\n\n\n\t\t\t没有找到学生!");
    Return_Menu();
}
//根据电话查找
void Find_Student_Tel(){
    struct student *stu;
    char Temp_Tel[12];
    printf("\n\n\t\t\t请输入电话\n\n\t\t电话:");
    stu = File_Student_Creat();
    scanf("%s",Temp_Tel);
    while(stu != NULL){
        if(strcmp(stu->Stu_Tel,Temp_Tel) == 0){
            system("clear");
            printf("\n\n\t\t\t已找到！");
            stu_print(stu);
            Return_Menu();
        }
        stu = stu->next;
    }
    printf("\n\n\n\t\t\t没有找到学生!");
    Return_Menu();
}
//根据学号查找
void Find_Student_Number(){
    struct student *stu;
    char Temp_Number[10];
    printf("\n\n\t\t\t请输入学号:\n\n\t\t学号::");
    stu = File_Student_Creat();
    scanf("%s",Temp_Number);
    while(stu != NULL){
        if(strcmp(stu->Stu_Number,Temp_Number) == 0){
            system("clear");
            printf("\n\n\t\t\t已找到!");
            stu_print(stu);
            Return_Menu();
        }
        stu = stu->next;
    }
    printf("\n\n\n\t\t\t没有找到学生!");
    Return_Menu();
}

//根据姓名查找
void Find_Student_Name(){
    struct student *stu;
    int i = 0;
    char Temp_Name[10];
    printf("\n\n\t\t\t请输入姓名:\n\n\t\t姓名:");
    stu = File_Student_Creat();
    scanf("%s",Temp_Name);
    while(stu != NULL){
        if(strcmp(stu->Stu_Name,Temp_Name) == 0){
            system("clear");
            printf("\n\n\t\t\t已找到！");
            stu_print(stu);
            Return_Menu();
        }
        stu = stu->next;
    }
    printf("\n\n\t\t\t没有找到学生!");
    Return_Menu();
}

//-------------------------------------------------用户登陆(目前只有单用户)--------------------------------------------------
void Stu_Login(){
    FILE *fp;
    char password_Input1[10];
    char password_Input2[10];
    fp = fopen("password.bat","ab+");
    system("clear");
    printf("\n\t\t\t请输入你的密码:\n");
    printf("\t\t密码:");
    scanf("%s",password_Input1);
    printf("\n\t\t\t请再次输入:\n");
    printf("\t\t密码:");
    scanf("%s",password_Input2);
    if(strcmp(password_Input1,password_Input2) == 0){
        fprintf(fp,"%s",password_Input1);
    }
    else{
        printf("\n\t\t两次密码不一致:");
        exit(1);
    }
    fclose(fp);
}


void Stu_Main(void){
    system("clear");
    FILE *fp;
    int i = 1;
    char password[10];
    char pd[10];
    printf("\n\t\t\t\t\t学生管理系统\n\n");
    fp = fopen("password.bat","ab+");
    if(fscanf(fp,"%s",password) == -1){
        printf("对不起，请先重置密码！");
        Stu_Login();
        Stu_Main();
    }
    else{
        loop:   printf("\n\t\t\t请输入你的密码(%d/3)",i);
        printf("\n\n\n\t\t\t密码:");
        scanf("%s",pd);
        if(strcmp(pd,password) == 0){
            printf("\n\n\t\t\t\t登陆成功!");
            return;
        }
        else {
            printf("\n\n\t\t\t密码错误!\n\n");
            if(i == 3) exit(1);
            i++;
            goto loop;
        }
    }
}
//--------------------------------------------------菜单框架-----------------------------------------------------------------
void Stu_Memu(){
    system("clear");
    int Stu_P;
    printf("\n----------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("\n\t\t\t\t学生管理系统\n\n");
    printf("\n\t\t\t\t请选择接下来的操作\n\n");
    printf("\n\t\t\t\t1:输入学生信息\n");
    printf("\n\t\t\t\t2:查找学生信息\n");
    printf("\n\t\t\t\t3:删除学生信息\n");
    printf("\n\t\t\t\t4:修改学生信息\n");
    printf("\n\t\t\t\t5:以列表浏览学生信息\n");
    printf("\n\t\t\t\t6:退出\n");
    scanf("%d",&Stu_P);
    switch(Stu_P){
        case 1:Input_Student();break;
        case 2:Find_Student();break;
        case 3:Delete_Student();break;
        case 4:Mod_Student();break;
        case 5:Look_Student_List();break;
        case 6:exit(1);
    }
}

int main(){
    Stu_Main();
    Stu_Memu();
    return 0;
}

