#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
int n; 
main()
{	int x,flag=1;
	while(1)
		{
		printf("		==========ѧ����Ϣ����ϵͳ==========\n");
		printf("		*        1.ѧ����Ϣ��������        *\n");
		printf("		*        2.ѧ������ͳ������        *\n");
		printf("		*        3.��ѯѧ������	           *\n");
		printf("		*        4.����ѧ������            *\n");
		printf("		*        5.��ʾ��ǰ�ɼ���          *\n");
		printf("		*        6.ɾ��ѧ������            *\n");
		printf("		*        7.�˳�ѧ����Ϣ����ϵͳ    *\n");
		printf("		====================================\n");
		printf("����Ҫִ�еĲ�����");
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
	printf("����Ҫ¼���ѧ��������");
	scanf("%d",&n); 
	for(i=0;i<n;i++)
	{
	printf("����ѧ����ѧ�ţ�");
	scanf("%d",&stu[i].number);
	printf("����ѧ����������");
	scanf("%s",&stu[i].name);
	printf("����ѧ�����Ա�");
	scanf("%c",&stu[i].sex);
	printf("����ѧ�������壺");
	scanf("%s",&stu[i].mingzu);
	printf("����ѧ���ĵ绰���룺");
	scanf("%d",&stu[i].phonenumber);
	printf("����ѧ���������");
	scanf("%s",&stu[i].sushe);
	printf("����ѧ�����ſεĳɼ�");
	for(j=0;j<3;j++)
		scanf("%d",&stu[i].score[j]); 
	
	}
}
