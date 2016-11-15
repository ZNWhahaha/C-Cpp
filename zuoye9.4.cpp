#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LEN 2
struct student
{	int number;
	char name[20];
	char sex;
	int sore[4];
	float jun; 
};
main()
{	struct student stu[LEN],t;
	int i,j,sum;
	float x;
	for(i=0;i<LEN;i++)
	{	printf("输入同学的学号：");
		scanf("%d",&stu[i].number);
		printf("输入同学的姓名：");
		scanf("%s",&stu[i].name);
		printf("输入学生的性别：");
		scanf("%s",&stu[i].sex);
		printf("输入学生的4门成绩："); 
		for(j=0;j<4;j++)
			scanf("%d",&stu[i].sore[j]);
	}
	for(i=0;i<LEN;i++)
	{	sum=0;
		for(j=0;j<4;j++)
		{
			sum=sum+stu[i].sore[j];
		}
		x=sum/4.0;
		stu[i].jun=x;
	}
	for(i=0;i<LEN-1;i++)
	{	for(j=0;j<LEN-1-i;j++)
		{	if(stu[i].jun<stu[j].jun)
			{	t=stu[i];
				stu[i]=stu[j];
				stu[j]=t;
			}
		}
	}
	for(i=0;i<LEN;i++)
	{	printf("\n该同学的学号：%d",stu[i].number);
		printf("\n该同学的姓名：%s",stu[i].name);
		printf("\n该学生的性别：%c",stu[i].sex);
		printf("\n该学生的4门成绩："); 
		for(j=0;j<4;j++)
			printf("%d ",stu[i].sore[j]);
		printf("\n该同学的平均成绩：%f",stu[i].jun);
		printf("\n\n");
	}
}
