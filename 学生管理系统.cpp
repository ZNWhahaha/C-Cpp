#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
int n; 
main()
{	int x,flag=1;
	while(1)
		{
		printf("		==========学生信息管理系统==========\n");
		printf("		*        1.学生信息键盘输入        *\n");
		printf("		*        2.学生数据统计排序        *\n");
		printf("		*        3.查询学生数据	           *\n");
		printf("		*        4.插入学生数据            *\n");
		printf("		*        5.显示当前成绩表          *\n");
		printf("		*        6.删除学生数据            *\n");
		printf("		*        7.退出学生信息管理系统    *\n");
		printf("		====================================\n");
		printf("输入要执行的操作：");
		scanf("%d",&x);
		switch(x)
		{
			case 1:
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
			case 6:
				break;
			case 7:
				flag=0;
				break;
		}
		if(flag==0)
			break;
	}
}
struct student
{	
	int number;
	char name[20];
	char sex;
	char mingzu[5];
	int phonenumber;
	char sushe[8];
	int score[3];
	float aver;
	int sum;
}stu[100];
void ownthing()
{	
	int i,j;
	printf("输入要录入的学生个数：");
	scanf("%d",&n); 
	for(i=0;i<n;i++)
	{
	printf("输入学生的学号：");
	scanf("%d",&stu[i].number);
	printf("输入学生的姓名：");
	scanf("%s",&stu[i].name);
	printf("输入学生的性别：");
	scanf("%c",&stu[i].sex);
	printf("输入学生的民族：");
	scanf("%s",&stu[i].mingzu);
	printf("输入学生的电话号码：");
	scanf("%d",&stu[i].phonenumber);
	printf("输入学生的宿舍号");
	scanf("%s",&stu[i].sushe);
	printf("输入学生三门课的成绩");
	for(j=0;j<3;j++)
		scanf("%d",&stu[i].score[j]); 
	
	}
}
