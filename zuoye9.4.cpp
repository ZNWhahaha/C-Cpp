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
	{	printf("����ͬѧ��ѧ�ţ�");
		scanf("%d",&stu[i].number);
		printf("����ͬѧ��������");
		scanf("%s",&stu[i].name);
		printf("����ѧ�����Ա�");
		scanf("%s",&stu[i].sex);
		printf("����ѧ����4�ųɼ���"); 
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
	{	printf("\n��ͬѧ��ѧ�ţ�%d",stu[i].number);
		printf("\n��ͬѧ��������%s",stu[i].name);
		printf("\n��ѧ�����Ա�%c",stu[i].sex);
		printf("\n��ѧ����4�ųɼ���"); 
		for(j=0;j<4;j++)
			printf("%d ",stu[i].sore[j]);
		printf("\n��ͬѧ��ƽ���ɼ���%f",stu[i].jun);
		printf("\n\n");
	}
}
