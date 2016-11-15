#include <stdio.h>
#define N 2
struct student
{
	char num[8];
	char name[20];
	char sex[10];
	int score[4];
	float aver;
};
struct student stu[N],h;
void jun(struct student stu[],int n)
{
	int sum,i,j;
	float t;
	for(i=0;i<n;i++)
	{
		sum=0;
		for(j=0;j<4;j++)
		{
			sum=sum+stu[i].score[j];
		}
		t=sum/4.0;
		stu[i].aver=t;
	}
}
main()
{
	int i,j,sum=0;
	printf("***please input the %d student information***\n",N);
	for(i=0;i<N;i++)
	{
		printf("第%d个学生\n",i+1);
		printf("num:");
		scanf("%s",stu[i].num);
		printf("name:");
		scanf("%s",stu[i].name);
		printf("sex:");
		scanf("%s",stu[i].sex);
		printf("score:");
			for(j=0;j<4;j++)
				scanf("%d",&stu[i].score[j]);
	}
	jun(stu,N);
	for(i=0;i<N-1;i++)
	{
		for(j=i+1;j<N;j++)
		{
			if(stu[i].aver<stu[j].aver)
			{
				h=stu[i];
				stu[i]=stu[j];
				stu[j]=h;
			}
		}
	} 
	for(i=0;i<N;i++)
	{
		printf("第%d个学生:\n",i+1);
		printf("num:%s\n",stu[i].num);
		printf("name:%s\n",stu[i].name);
		printf("sex:%s\n",stu[i].sex);
		for(j=0;j<4;j++)
		{
			printf("score:%d ",stu[i].score[j]);
		}
		printf("\n");
		printf("average:%f\n",stu[i].aver);
	} 
}
