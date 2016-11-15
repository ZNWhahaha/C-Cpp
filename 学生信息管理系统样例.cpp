#include"stdio.h"
#include"conio.h"
#include"string.h"
#include"stdlib.h"
void look(); /*声明查看函数*/
void save(); /*声明保存函数*/
void search_name(); /*声明按姓名查看函数*/
void search_number(); /*声明按学号查看函数*/
void order(); /*声明排序函数*/
void del(); /*声明删除函数*/
int openl(); /*声明打开函数*/
void welcome(); /*声明我的个人信息函数*/
void type(); /*声明输入函数*/
void see(); /*声明打开并查看文件函数*/
struct student /*定义学生信息的结构体类型*/
{
char num[15]; /*学号*/
char name[20]; /*姓名*/
char sex[4]; /*性别*/
int english; /*英语成绩*/
int math; /*数学成绩*/
int chinese; /*语文成绩*/
float aver; /*平均成绩*/
float sum; /*总成绩*/
}stu[100];
int n; /*声明一个全局变量*/
main() /*主函数即用户的操作界面*/
{ 
system("color 1E"); /*设计文本颜色*/
int b,flag=0; /*声明局部变量*/
while(1) /*循环输出以下信息*/
{
printf("\n\t\t\t欢迎来到学生成绩管理系统!\n");
printf("\n\t\t\t\t ###制作\n");
printf("\t\t\t-------------------------------\n");
printf("\t\t\t1.键入学生的信息\n\n"); /*键入学生的信息*/
printf("\t\t\t2.查看录入的学生信息\n\n"); /*查看录入的学生信息*/
printf("\t\t\t3.按姓名查看学生的信息\n\n"); /*按姓名查看学生的信息*/
printf("\t\t\t4.按学号查看学生的信息\n\n"); /*按学号查看学生的信息*/
printf("\t\t\t5.按平均成绩排序\n\n"); /*排序*/
printf("\t\t\t6.删除学生信息\n\n"); /*删除学生信息*/
printf("\t\t\t7.保存学生信息\n\n"); /*保存*/
printf("\t\t\t8.打开文件\n\n"); /*打开文件*/
printf("\t\t\t9.我的个人信息\n\n"); /*我的个人信息*/
printf("\t\t\t0.退出\n\n"); /*退出*/
printf("\t\t\t请输入你的选择:");
scanf("%d",&b);
switch(b)
{
case 1:type();break; /*调用键入学生信息函数*/
case 2:look();break; /*调用查看函数*/
case 3:search_name();break; /*调用姓名查看函数*/
case 4:search_number();break; /*调用学号查看函数*/
case 5:order();break; /*调用排序函数*/
case 6:del();break;/*调用删除函数*/
case 7:save();break;/*调用保存函数*/
case 8:see();break;/*调用打开文件函数*/
case 9:welcome();break;/*调用我的个人信息函数*/
case 0:flag=1;break;/*退出SWITCH语句*/
default :printf("错误!");
}
if(flag) break; /*如果选择0就退出循环*/
}
}
void welcome() /*我的个人信息函数*/
{
system("CLS");
printf("\n\n\t\t------------个人信息------------"); /*在屏幕上输出一下信息*/
printf("\n\n\n\n\t\t姓名:###");
printf("\t\t\tSex:#\n");
printf("\t\t年龄:#\n");
printf("\n\t\t\t--------学习经历--------\n\n\n");
printf("\t\t小学:######\n\n");
printf("\t\t初中:#####\n\n");
printf("\t\tS高中:######\n\n");
printf("\t\t大学:######\n\n");
printf("\n\n\t\t按任意键返回欢迎屏幕!");
getch(); /*按任意键返回主函数*/
}
void type() /*定义键入学生信息函数*/
{	
system("CLS");
int i; /*定义局部变量*/
printf("\t\t输出你想输入的学生信息个数:");
scanf("%d",&n);
for(i=0;i<n;i++) /*输入每个学生的信息*/
{
printf("\n\t\t\t----------------\n");
printf("\t\t\t学号:");
scanf("%s",&stu[i].num); /*输入学号*/
printf("\t\t\t姓名:");
scanf("%s",&stu[i].name); /*输入姓名*/
printf("\t\t\t性别:");
scanf("%S",&stu[i].sex); /*输入性别*/
printf("\t\t\t英语:");
scanf("%d",&stu[i].english); /*输入英语成绩*/
printf("\t\t\t数学:");
scanf("%d",&stu[i].math); /*输入数学成绩*/
printf("\t\t\t语文:");
scanf("%d",&stu[i].chinese); /*输入语文成绩*/
stu[i].aver=((float)stu[i].english+(float)stu[i].math+(float)stu[i].chinese)/3;/*计算平均成绩*/
stu[i].sum=(float)stu[i].english+(float)stu[i].math+(float)stu[i].chinese;/*计算总成绩*/
printf("\t\t\t平均成绩=%4.1f\n",stu[i].aver); /*输出平均成绩*/
printf("\t\t\t总成绩=%4.1f\n",stu[i].sum); /*输出总成绩*/
}
printf("\n\n\t\t\t按任意键返回菜单!!");
getch();
save();
}
void save() /*建立保存文件函数*/
{	
system("CLS");
FILE *fp; /*定义文件型指针*/
int i;
if((fp=fopen("student.txt","wb"))==NULL) /*打开输出文件*/
{
printf("不能打开文件！\n"); 
return; /*终止程序*/
}
for(i=0;i<n;i++) /*向student文件中写入信息*/
if(fwrite(&stu[i],sizeof(struct student),1,fp)!=1)
printf("文件写入错误\n");
fclose(fp); /*关闭文件*/
printf("\n\n\n\n\t\t\t学生信息保存成功!\n");
printf("\n\n\n\n\t\t\t按任意键返回菜单!!");
getch();
}
void look() /*定义查看函数*/
{	
system("CLS");
int i;
//n=openl(); /*调用openl函数*/
printf("\t学号\t姓名\t性别\t英语\t数学\t语文\t平均成绩\t总成绩\n");
for(i=0;i<n;i++) /*输出所有的学生信息*/
{
printf("%10s\t%s\t%2s\t%d\t%d\t%d\t%3.1f\t\t%6.1f\n",stu[i].num,stu[i].name,
stu[i].sex,stu[i].english,stu[i].math,stu[i].chinese,stu[i].aver,stu[i].sum);
}
printf("\n\n\n\t\t\t按任意键返回菜单");
getch();
}
void search_name() /*按姓名查看函数*/
{	
system("CLS");
int i;
char name[20]; /*声明字符数组*/
printf("\t\t\t请输入学生姓名:\n");
scanf("%s",name);
printf("\t学号\t姓名\t性别\t英语\t数学\t语文\t平均成绩\t总成绩\n");
for(i=0;i<n;i++)
if(strcmp(stu[i].name,name)==0) /*将输入的姓名与结构体中的姓名进行比较*/
{
printf("%10s\t%s\t%2s\t%d\t%d\t%d\t%3.1f\t\t%6.1f\n",stu[i].num,stu[i].name,
stu[i].sex,stu[i].english,stu[i].math,stu[i].chinese,stu[i].aver,stu[i].sum);
printf("\n\n\n\t\t\t按任意键返回菜单");
}
getch();
}
void search_number() /*定义按学号查看函数*/
{	
system("CLS");
int i;
char number[15]; /*声明字符数组*/
printf("\t\t\t请输入学号:\n");
scanf("%s",number);
printf("\t学号\t姓名\t性别\t英语\t数学\t语文\t平均成绩\t总成绩\n");
for(i=0;i<n;i++)
if(strcmp(stu[i].num,number)==0) /*将输入的学号与结构体中的学号进行比较*/
printf("%10s\t%s\t%2s\t%d\t%d\t%d\t%3.1f\t\t%6.1f\n",stu[i].num,stu[i].name,
stu[i].sex,stu[i].english,stu[i].math,stu[i].chinese,stu[i].aver,stu[i].sum);
printf("\n\n\n\t\t\t按任意键返回菜单");
getch();
}
void order() /*定义排序函数*/
{
system("CLS");
int i,j;
char a;
struct student temp; /*声明结构体变量*/
printf("\t学号\t姓名\t性别\t英语\t数学\t语文\t平均成绩\t总成绩\n");
for(i=0;i<n;i++) /*对数据进行排序*/
{
for(j=i+1;j<n;j++)
if(stu[i].sum<stu[j].sum)
{
temp=stu[i];
stu[i]= stu[j];
stu[j]=temp;
}
printf("%10s\t%s\t%2s\t%d\t%d\t%d\t%3.1f\t\t%6.1f\n",stu[i].num,stu[i].name,
stu[i].sex,stu[i].english,stu[i].math,stu[i].chinese,stu[i].aver,stu[i].sum);
}
getch();
printf("是否保存？(y or n)");
getchar();
scanf("%c",&a);
if(a=='y') /*是否保存排序后的文件*/
save();
else
printf("退出");
getch();
}
void del() /*定义删除学生信息函数*/
{
int i;
char a;
char name[20];
system("CLS");
printf("\t\t\t输入学生名字:\n");
scanf("%s",name);
system("CLS");
printf("\t学号\t姓名\t性别\t英语\t数学\t语文\t平均成绩\t总成绩\n");
for(i=0;i<n;i++)
if(strcmp(stu[i].name,name)==0)
{
printf("%10s\t%s\t%2s\t%d\t%d\t%d\t%3.1f\t\t%6.1f\n",stu[i].num,stu[i].name,
stu[i].sex,stu[i].english,stu[i].math,stu[i].chinese,stu[i].aver,stu[i].sum);
getch();
printf("真的删除?(y or n)");
getchar();
scanf("%c",&a);
if(a=='y') /*是否删除该信息*/
{
for(;i<n;i++)
stu[i]=stu[i+1];
n=n-1;
printf("你已经删除信息");
}
else
printf("退出");
getch();
}
save();
}
int openl() /*定义打开文件函数*/
{	
system("CLS");
int i;
FILE *fp;
if((fp=fopen("student.txt","rb"))==NULL)
{
printf("Cannot open file.\n");
exit(0);
}
for(i=0;!feof(fp);i++)
fread(&stu[i],sizeof(struct student),1,fp);
fclose(fp);
return(i-1);
}
void see() /*打开并查看文件*/
{	
system("CLS");
int i;
n=openl();
printf("文件打开成功!\n");
printf("按任意键查看!\n");
getch();
printf("\t学号\t姓名\t性别\t英语\t数学\t语文\t平均成绩\t总成绩\n");
for(i=0;i<n;i++) /*输出所有的学生信息*/
{
printf("%10s\t%s\t%2s\t%d\t%d\t%d\t%3.1f\t\t%6.1f\n",stu[i].num,stu[i].name,
stu[i].sex,stu[i].english,stu[i].math,stu[i].chinese,stu[i].aver,stu[i].sum);

}
printf("\n\n\n\t\t\t按任意键返回菜单");
getch();
