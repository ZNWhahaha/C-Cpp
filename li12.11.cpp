#include<stdio.h>
#include<stdlib.h>
#include<conio.h> 
struct student
{	char name[20];
	int number;
	int age;
	char sex;
	int store[3];
	struct student *next;
};
struct student *jianli()
{	struct student *head,*r,*stu;
	int j,i=0;
	char x;
	head=(struct student *)malloc(sizeof(struct student));
	head->next=NULL;
	r=head;
	do
	{	stu=(struct student *)malloc(sizeof(struct student));
		printf("\n\n第%i个人的信息：",++i);
		printf("\n输入姓名：");
		gets(stu->name);
		printf("输入学号：");
		scanf("%d",&stu->number);
		printf("输入年龄：");
		scanf("%d",&stu->age);
		printf("输入性别：");
		scanf("%s",&stu->sex);
		printf("输入语数外三门课的成绩：");
		for(j=0;j<3;j++)
			scanf("%d",&stu->store[j]);
		r->next=stu;
		r=stu;
		printf("输入是否继续：(Y/N)");
		x=getche();
	}while(x=='Y'||x=='y');
	r->next=NULL;
	return head;
}
void save(struct student *head)
{	struct student *stu;
	FILE *fp;
	char filename[40];
	printf("\n\n输入要保存的文件名：");
	scanf("%s",filename);
	if((fp=fopen(filename,"wt"))==NULL)
	{	printf("文件出错，按任意键退出！");
		getch();
		exit(1);	
	}
	/*stu=head;
	while(stu!=NULL)
	{	fwrite(stu,sizeof(struct student),1,fp);
		stu=stu->next;
	}*/
	for(stu=head->next;stu!=NULL;stu=stu->next)
		fprintf(fp,"%s %d %d %s %d %d %d",stu->name,stu->number,stu->age,stu->sex,
		stu->store[0],stu->store[1],stu->store[2]);
	printf("\n文件已保存成功，按任意键返回！");
	getch();
	fclose(fp);
} 
struct student *read()
{	struct student *head,*r,*stu;
	FILE *fp;
	char filename[40];
	printf("输入要打开的文件名：");
	gets(filename);
	if((fp=fopen(filename,"rt"))==NULL)
	{	printf("读文件出错，按任意键退出！");
		getch();
		exit(1);
	} 
	head=(struct student *)malloc(sizeof(struct student));
	head->next=NULL;
	r=head;
	while(!feof(fp))
	{	stu=(struct student *)malloc(sizeof(struct student));
		fscanf(fp,"%s %d %d %s %d %d %d",stu->name,&stu->number,&stu->age,stu->sex,
		&stu->store[0],&stu->store[1],&stu->store[2]);
		r->next=stu;
		r=stu;
	}
	r->next=NULL;
	fclose(fp);
	printf("文件输出正确，按任意键退出！");
	getch();
	return head;
}
void printf(struct student *head)
{	struct student *stu;
	printf("\n该班的数据为：");
	printf("姓名\t学号\t年龄\t性别\t语文成绩\t数学成绩\t英语成绩\t\n");
	for(stu=head;stu!=NULL;stu=stu->next)
	printf("%s\t%d\t%d\t%s\t%d\t%d\t%d\t");
}
main()
{	struct student *head;
	head=jianli();
	save(head);
	head=read();
	printf(head);
}
