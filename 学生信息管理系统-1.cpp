#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct student{
	char num[10];
	char name[20];
	int  score[3];
	int grades;
	struct student *next;
};
typedef struct student DATE;
void Menu(){
	
	printf("*************************欢迎访问学生成绩管理系统*************************\n\n\n");
	printf("                      1---学生信息数据的录入\n");
	printf("                      2---显示所有的学生信息\n");
	printf("                      3---学生信息数据追加\n");
	printf("                      4---学生信息数据修改\n");
	printf("                      5---学生信息数据删除\n");
	printf("                      6---学生信息数据查询\n");
	printf("                      0---退出系统\n"); 
	printf("\n\n\n***************************************************************************");
	printf("\n请在0-6中选择，以回车键结束\n");
}
int icount;
DATE *Creat(){	
	FILE *fp;						//学生数据信息录入 
	DATE *head=NULL;
	DATE *p1,*p2;
	char filename[50];
	int i,sum=0;
	printf("写文件程序......\n");
	printf("请输入要打开文件的完整路径及文件名:");
	scanf("%s",filename);
	fp=fopen(filename,"wt");
	if(fp==NULL){
		printf("\n文件打开失败，%s可能不存在\n",filename);
	//	getch();
		exit(0);
	}
	p1=p2=(DATE *)malloc(sizeof(DATE));
	icount=0;
	printf("请输入学生的信息(如果输入学生学号为'#',则停止输入,并按回车键选择其他操作)：\n");
	printf("请输入学生的学号：");
	scanf("%s",p1->num);
	do{
		icount++;
		printf("\n请输入学生的姓名：");
		scanf("%s",p1->name);
		printf("请分别输入学生的高数，英语，计算机成绩：");
		sum=0;
		for(i=0;i<3;i++){
			scanf("%d",&p1->score[i]);
			sum+=p1->score[i];
		} 
		p1->grades=sum; 
		printf("学生成绩总分：%d\n",p1->grades);
		if(icount==1){
			p1->next=head;
			p2=p1;
		}
		else{
			p1->next=NULL;
			p2->next=p1;
			p2=p1;
		}
		fprintf(fp,"%s %s %d %d %d %d",p1->num,p1->name,p1->score[0],p1->score[1],p1->score[2],p1->grades);
//		fwrite(p1,sizeof(DATE),1,fp);
		p1=(DATE *)malloc(sizeof(DATE));
		printf("请输入学生的学号：");
		scanf("%s",p1->num);
	}while(strcmp("#\0",p1->num));
	fclose(fp);
	free(p1);
	return(head); 
} 
DATE *Print(){								//将学生信息从文件中取出保存到链表中 
	DATE *pt,*head=NULL,*pi;
	FILE *fp;
	pt=pi=(DATE *)malloc(sizeof(DATE));
	fp=fopen("students_information.txt","rt");
	if(fp==NULL){
		printf("\n文件打开失败，student_information.txt可能不存在\n");
	//	getch();
		exit(0);
	}
	int n=0,i;	
	head=pt;
	pt->next=NULL;
	while(fscanf(fp,"%s %s %d %d %d %d",pt->num,pt->name,&pt->score[0],&pt->score[1],&pt->score[2],&pt->grades)!=EOF){
		n++;
		pi=pt;
		pt=(DATE *)malloc(sizeof(DATE));
		pi->next=pt;
		pt->next=NULL;
	}
	fclose(fp);
	return (head);
}
void Input(){							//显示所有学生的数据信息 
	DATE *p,*phead;
	phead=Print();
	p=phead;
	while(p!=NULL){
		printf("学号：%s",p->num);
		printf("姓名：%s",p->name);
		printf("高数，英语，计算机：%d\t%d\t%d\t",p->score[0],p->score[1],p->score[2]);
		printf("总分：%d",p->grades);
		p=p->next;
	}
}
Add(){								//学生数据信息的追加 
	
	
	
	
}
Change(){							//学生数据信息修改 
	
	
	
	
	
}
Delete(){							//学生数据信息删除 
	
	
	
	
	
}
Search(){							//学生数据信息查询 
	
	
	
	
	
} 
main(){
	int choice;
	DATE *phead;
	Menu();
	scanf("%d",&choice);
	do{
		switch(choice){
			case 1:phead=Creat();	break;
			case 2:Input();	break;
			case 3:Add();	break;
			case 4:Change();break;
			case 5:Delete();break;
			case 6:Search();break;
			case 0:         break;
		}
		printf("是否继续操作,如果想要退出系统可以选择'0'，并按回车键\n");
		printf("请选择：");
		scanf("%d",&choice); 	
	}while(choice!=0);
}
