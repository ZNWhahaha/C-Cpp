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
		printf("\n\n��%i���˵���Ϣ��",++i);
		printf("\n����������");
		gets(stu->name);
		printf("����ѧ�ţ�");
		scanf("%d",&stu->number);
		printf("�������䣺");
		scanf("%d",&stu->age);
		printf("�����Ա�");
		scanf("%s",&stu->sex);
		printf("�������������ſεĳɼ���");
		for(j=0;j<3;j++)
			scanf("%d",&stu->store[j]);
		r->next=stu;
		r=stu;
		printf("�����Ƿ������(Y/N)");
		x=getche();
	}while(x=='Y'||x=='y');
	r->next=NULL;
	return head;
}
void save(struct student *head)
{	struct student *stu;
	FILE *fp;
	char filename[40];
	printf("\n\n����Ҫ������ļ�����");
	scanf("%s",filename);
	if((fp=fopen(filename,"wt"))==NULL)
	{	printf("�ļ�������������˳���");
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
	printf("\n�ļ��ѱ���ɹ�������������أ�");
	getch();
	fclose(fp);
} 
struct student *read()
{	struct student *head,*r,*stu;
	FILE *fp;
	char filename[40];
	printf("����Ҫ�򿪵��ļ�����");
	gets(filename);
	if((fp=fopen(filename,"rt"))==NULL)
	{	printf("���ļ�������������˳���");
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
	printf("�ļ������ȷ����������˳���");
	getch();
	return head;
}
void printf(struct student *head)
{	struct student *stu;
	printf("\n�ð������Ϊ��");
	printf("����\tѧ��\t����\t�Ա�\t���ĳɼ�\t��ѧ�ɼ�\tӢ��ɼ�\t\n");
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
