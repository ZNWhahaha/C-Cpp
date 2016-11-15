#include<stdio.h> 
#include<stdlib.h>
#include<string.h>

#define LEN sizeof(struct node)
#define PRINT "%5d%10s%  -5d%8s%10s%6s%8s\n",p->num,p->week,p->time,p->major,p->lesson,p->teacher,p->room
#define PRINT_1 "�������   ����   �ν���    רҵ      ����      ��ʦ     ����      \n"
	struct node* num(void) ;      //��������Ϣ->38
	struct node *creat(void);     //����������->
	void print(struct node *head);    //��ӡ������-> 
	void insert(struct node *p,struct node *px);    //���½��ӵ�����β������->
	void fprint(struct node *head) ;             //����������ݵ����ļ��еĺ���->
	struct node * load(void) ;       //���ļ��е�����ȡ�����������еĺ���->
	void find_1();                 //����ѡ�� ����->
	void menu();                   //�˵�����-> 
	void num_find(struct node *head,int h);       //����Ų������ݺ��� 
	void week_find(struct node *head,char s[]);    //�����ڲ������ݺ��� 
	void teacher_find(struct node *head, char s[] ); //����ʦ�������ݺ��� 
	void room_find(struct node *head,char s[]);       //�����Ҳ������ݺ��� 
	void num_dele(struct node *head,int n);         //�������ź�ɾ��
	void room_dele(struct node *head,char arr[]) ;   //�����Һ�ɾ�� 
	void num_mod(struct node *head,int m,int n);     
	void num_mod2(struct node *head,int m,int n);          //�޸Ľ�����ź��� 
	void week_mod(struct node *head,int m,char nmod[]);
	void week_mod2(struct node *head,int m,char nmod[]);    //�޸����ں���   
	void time_mod(struct node *head,int oo,int xx);
	void time_mod2(struct node *head,int oo,int xx);        //�޸��Ͽ�ʱ�亯��
	void major_mod(struct node *head,int m,char nmod[]);
	void major_mod2(struct node *head,int m,char nmod[]);   //�޸�רҵ���� 
	void lt_mod(struct node *head,int m,char nmod[],char nname[]);
	void lt_mod2(struct node *head,int m,char nmod[],char nname[]);     //�Ͽγ��޸ĺ��� 
	struct node *sort_num(struct node *head);     //��������   ѡ����뷨 ���� 
	struct node *sort_week(struct node *head);
	struct node *sort_week1(struct node *head);
	void link(struct node *head1,struct node *head2);
struct node         //�����Ϣ 
{
	int num;
	char week[10];
	int time;
	char major[10];
	char lesson[10];
	char teacher[10];
	char room[10];
	struct node *next;
};

int maxlen=1;
 
/********************************************************************************************/ 
struct node* num(void)        //��װ������¼����Ϣ 
{
	int w;
	struct node *head,*p1;
	head=p1=(struct node *)malloc(LEN) ;
	printf("�����������ţ�\n");
	scanf("%d",&p1->num);
	pp:	printf("��ѡ����Ҫ��������ڣ�\n");
	printf("   1.����һ\n");
	printf("   2.���ڶ�\n");
	printf("   3.������\n");
	printf("   4.������\n");
	printf("   5.������\n");
	printf("   6.������\n");
	printf("   7.������\n");
	printf("��ѡ��\n");
	scanf("%d",&w);
	getchar();
	if(w==1)
	{
		strcpy(p1->week,"����һ");
	}
	else if(w==2)
	{
		strcpy(p1->week,"���ڶ�");
	}
	else if(w==3)
	{
		strcpy(p1->week,"������");
	}
	else if(w==4)
	{
		strcpy(p1->week,"������");
	}
	else if(w==5)
	{
		strcpy(p1->week,"������");
	}
	else if(w==6)
	{
		strcpy(p1->week,"������");
	}
	else if(w==7)
	{
		strcpy(p1->week,"������");
	}
	else if(w>7||w<1)
	{
		printf("ѡ�����  ������ѡ��\n");
		goto pp;
	}
	printf("�������Ͽ�ʱ�䣨�ߵ㵽ʮ��Ϊ  1��:\n");
	scanf("%d",&p1->time);
	getchar();
	printf("������רҵ����������̣�:\n");
	scanf("%s",p1->major);
	getchar();
	printf("������γ̣���c���ԣ�:\n");
	scanf("%s",p1->lesson);
	getchar();
	printf("��������ʦ(������):\n");
	scanf("%s",p1->teacher);
	getchar();
	printf("��������Һţ���FZ155��:\n");
	scanf("%s",p1->room);
	getchar();
	p1->next=NULL;
	return head;
}
/************************************************************************************************/ 
struct node *creat(void)     //����һ������  
{
	struct node *head=NULL,*p1=NULL,*p2=NULL;
	head=p1=p2=num() ;
	while(p1->num!=0)      //ÿ���ڵ����ϸ����� 
	{
		system("cls");
		p2->next=p1;
		p2=p1;
		maxlen++;
		p1=num();
	}
	p2->next=NULL;
	return head;
}
/*******************************�������*********************************/ 
void print(struct node *head)
{
	struct node *p;
	p=head;
	if(p==NULL)
	{
		printf("������Ϊ�գ�");
	}
	else
	{
		while(p!=NULL)
		{
			printf(PRINT);
			p=p->next; 
		}
	}
	printf("\n");
}
/*************************************************************************/
 void insert(struct node *p,struct node *px)
{
	if(p==NULL)
	{
		p=px;
		p->next=NULL;
	}
	else
	{
		while(p->next)
		{
			p=p->next;
		}
		p->next=px;
		p=p->next;
		p->next=NULL;
	}
}
/**********************************************************************************************/
void fprint(struct node *head) 
{
	FILE *fp;
	struct node *p;
	p=head;
	if((fp=fopen("data.txt","w"))==NULL)
	{
		printf("�ļ���ʧ�ܣ�\n");
		exit(0);
	}
	else
	{
		while(p)
		{
			fprintf(fp,"%d %s %d %s %s %s %s ",p->num,p->week,p->time,p->major,p->lesson,p->teacher,p->room);
			p=p->next; 
		}
		printf("����ɹ�������\n");
		fclose(fp);
	}
}
/************************************************************************************************/
void judge(struct node *head)             //�ж��Ƿ񱣴溯�� 
{
	char ch_2;
	printf("�Ƿ񱣴���Ϣ����y/n)");
	ch_2=getchar();
	getchar();
	while(ch_2!='y'&&ch_2!='n')
	{
		printf("\t����������������룺\n\n") ;
		ch_2=getchar();
		getchar();
	}
	if(ch_2=='y')
	{
		fprint(head);    //��������Ϣ�����ļ� 
	}
	else
	{
		menu();
	}
}

/****************************************************************************************/
struct node * load(void)        //���ļ��е�����ȡ������������ 
{
	FILE *fp;
	struct node *head,*p1,*p2;
	head=p1=p2=NULL;
	if((fp=fopen("data.txt","r"))==NULL)
	{
		printf("�ļ�Ϊ�գ�����¼�����ݣ�лл������\n\n");
		menu();
	}
	else
	{
		while(!feof(fp))
		{
			p1=(struct node *)malloc(LEN);
			fscanf(fp,"%d %s %d %s %s %s %s ",&p1->num,p1->week,&p1->time,p1->major,p1->lesson,p1->teacher,p1->room);
			if(head==NULL)
			{
				head=p1;
			}
			else
			{
				p2->next=p1;
			}
			p2=p1;
		}
		p2->next=NULL;
		fclose(fp);
	}
	return head;
}

/****************************************************************************************************/
void find(struct node *head)                 //����ѡ�� 
{
	int k,h;
	char a[15] ;
	printf("****************************************\n");
	printf("        1.����Ų���\n");
	printf("        2.�����ڲ���\n");
	printf("        3.����ʦ����\n");
	printf("        4.�����Ҳ���\n");
	printf("****************************************\n");
	printf("      ��������ţ�\n");
	scanf("%d",&k);
	getchar();
	while(k<1||k>4)
	{
		printf("����������������룺\n");
		scanf("%d",&k);
		getchar();
	}
	if(k>=1&&k<=4)
	{
		switch(k)
		{
			case 1:
				printf("����������Ҫ���ҵĽ������:\n");
				scanf("%d",&h);
				getchar();
				num_find(head,h);
				break;
			case 2:
				printf("��������Ҫ��ѯ������:���� ����һ ��\n");
				gets(a);
				week_find(head,a);
				break;
			case 3:
				printf("��������Ҫ���ҵ���ʦ��(�� ���� )\n") ;
				gets(a);
				teacher_find(head,a);
				break;
			case 4:
				printf("��������Ҫ���ҵĽ��ң�(�� FZ155)\n");
				gets(a);
				room_find(head,a);
				break;			
		}
	}
}
void num_find(struct node *head,int h)       //����Ų��ҽ��Һ��� 
{
	struct node *p=head;
	int i=1;
	if(p==NULL)
	{
		printf("����Ϊ�գ����ȵ������ݣ�\n");
		p=load();
	}
	else
	{
		while(p!=NULL && i<h)
		{
			p=p->next;
			i++;
		}
		printf("��%d���ҵ�����Ϊ:\n\n",i);
		printf(PRINT_1) ;
		printf(PRINT);
	}
}
void week_find(struct node *head,char s[])     //�����ڲ������ݺ��� 
{
	struct node *p=head;
	int i=0,flag=1;
	if(p==NULL)
	{
		printf("����Ϊ�գ����ȵ������ݣ�\n");
		p=load();
	}
	else
	{
		for(i=0;i<=maxlen;i++)      // maxlen������ĳ��� 
		{
			while(p!=NULL && strcmp(p->week,s))   
			{
				p=p->next;
			} 
			if(p==NULL) 
			{
				printf("δ�ҵ�%s������\n\n",s);
				break;
			}
			else if(flag==1)
			{
				printf("��Ҫ��ѯ��%s������Ϊ:\n",s);
				printf(PRINT_1) ;
				printf(PRINT);
				flag++;
				p=p->next;
			}
			else if(flag!=1)
			{
				printf(PRINT);
				p=p->next;
			}
		}
	}
}
void teacher_find(struct node *head, char s[])          //����ʦ���Һ��� 
{
	struct node *p=head;
	int i=0,flag=1;
	if(p==NULL)
	{
		printf("����Ϊ�գ����ȵ������ݣ�\n");
		p=load();
	}
	else
	{
		for(i=0;i<=maxlen;i++)                     // maxlen������ĳ��� 
		{
			while(p!=NULL && strcmp(p->teacher,s))    
			{
				p=p->next;
			} 
			if(p==NULL) 
			{
				printf("δ�ҵ�%s������\n\n",s);
				break;
			}
			else if(flag==1)
			{
				printf("��Ҫ��ѯ��%s������Ϊ:\n",s);
				printf(PRINT_1) ;
				printf(PRINT);
				flag++;
				p=p->next;
			}
			else if(flag!=1)
			{
				printf(PRINT);
				p=p->next;
			}
		}
	}
}

 void room_find(struct node *head,char s[])       //���Է�װ���������������������������������� 
 {
	struct node *p=head;
	int i=0,flag=1;
	if(p==NULL)
	{
		printf("����Ϊ�գ����ȵ������ݣ�\n");
		p=load();
	}
	else
	{
		for(i=0;i<=maxlen;i++)      // maxlen������ĳ��� 
		{
			while(p!=NULL && strcmp(p->room,s))     
			{
				p=p->next;
			} 
			if(p==NULL) 
			{
				printf("δ�ҵ�%s������\n\n",s);
				break;
			}
			else if(flag==1)
			{
				printf("��Ҫ��ѯ��%s������Ϊ:\n",s);
				printf(PRINT_1) ;
				printf(PRINT);
				flag++;
				p=p->next;
			}
			else if(flag!=1)
			{
				printf(PRINT);
				p=p->next;
			}
		}
	}
}
void dele(struct node *head)
{
	int dele_x,m;
	char char_x[12];
	printf("\t1.������ţ�\n");
	printf("\t2.���Һ�\n");
	scanf("%d",&dele_x);
	getchar();
	while(dele_x!=1 && dele_x!=2)
	{
		printf("�������,���������룺\n");
		scanf("%d",&dele_x);
		getchar();
	}
	if(dele_x==1)
	{
		printf("������Ҫɾ���Ľ�����ţ�\n");
		scanf("%d",&m);
		getchar();
		num_dele(head,m);
		maxlen--;
	}
	else if(dele_x==2)
	{
		printf("������Ҫɾ���Ľ��Һţ�(�� FF155)\n");
		gets(char_x);
		room_dele(head,char_x);
		maxlen--;
	}
}

void num_dele(struct node *head,int n)       //���������ɾ���ĺ��� 
{
	struct node *p=head,*p2=NULL;
	int i=1;
	if(p==NULL) 
	{
		printf("����Ϊ�գ����ȵ������ݣ�\n");
		p=load();
	}
	else
	{
		while(p!=NULL && i<n)
		{
			p2=p;
			p=p->next;
			i++;
		}
		if(p==NULL)
		{
			printf("ɾ����λ�ò����ڣ�\n");
		}
		else
		{
			p2->next=p->next;
			free(p);
			printf("ɾ���ɹ���\n\n");
		}
	}
}

void room_dele(struct node *head,char s[])      //�����Һ�ɾ���ĺ��� 
{
	struct node *p=head,*p2=NULL;
	int i=0;
	if(p==NULL) 
	{
		printf("����Ϊ�գ����ȵ������ݣ�\n");
		p=load();
	}
	else
	{
			while(p!=NULL && strcmp(p->room,s))     
			{
				p2=p;
				p=p->next;
			} 
			if(p==NULL) 
			{
				printf("δ�ҵ�%s������\n\n",s);
			}
			else
			{
				p2->next=p->next;
				free(p);
				printf("ɾ���ɹ���\n\n");
			}
	}
}
void mod(struct node *head)        //�޸Ľ����Ϣ�ĺ��� 
{
	struct node *p=head;
	char arr[20];
	char nname[20],nmod[20];
	int xx ,oo;
	printf("��������Ҫ�޸ĵ���Ŀ����\n\n");
	gets(arr);
	if(!strcmp("�������",arr))
	{
		printf("��������Ҫ�޸ĵĽ�����ź��޸�Ϊ�Ľ�����ţ�\n");
		scanf("%d%d",&oo,&xx);
		getchar();
		num_mod(head,oo,xx);
		printf("�޸ĺ������Ϊ��\n\n");
		print(head);
	}
	else if(!strcmp("����",arr)) 
	{
		printf("��������Ҫ�޸����ڵĽ�����ţ�\n");
		scanf("%d",&oo);
		getchar();
		printf("��������Ҫ�޸ĺ������: \n");
		gets(nmod);
		week_mod(head,oo,nmod);
		printf("�޸ĺ������Ϊ��\n\n");
		print(head);
	}
	else if(!strcmp("�Ͽ�ʱ��",arr))
	{
		printf("��������Ҫ�޸��Ͽ�ʱ��Ľ�����ţ�\n");
		scanf("%d",&oo);
		getchar();
		printf("��������Ҫ�޸ĺ���Ͽ�ʱ��: \n");
		scanf("%d",&xx) ;
		getchar();
		time_mod(head,oo,xx);
		printf("�޸ĺ������Ϊ��\n\n");
		print(head);
	}
	else if(!strcmp("רҵ����",arr))
	{
		printf("��������Ҫ�޸��Ͽ�ʱ��Ľ�����ţ�\n");
		scanf("%d",&oo);
		getchar();
		printf("��������Ҫ�޸ĺ��רҵ����:\n");
		gets(nmod);
		week_mod(head,oo,nmod);
		printf("�޸ĺ������Ϊ��\n\n");
		print(head);
	}
	else if(!strcmp("�γ�����",arr)||!strcmp("��ʦ����",arr))
	{
		printf("��������Ҫ�޸��Ͽ�ʱ��Ľ�����ţ�\n");
		scanf("%d",&oo);
		getchar();
		printf("��������Ҫ�޸ĺ�Ŀγ�����:\n");
		gets(nmod);
		printf("��������Ҫ�޸ĺ����ʦ����:\n") ;
		gets(nname) ;
		lt_mod(head,oo,nmod,nname);
		printf("�޸ĺ������Ϊ��\n\n");
		print(head);
	}
	else
	{
		printf("�������\n");
	}
}
/*************************************************************************************************/
void num_mod(struct node *head,int m,int n)
{
	char ch_3;
	num_find(head,m);
	printf("\t�Ƿ�ȷ���޸ģ���y/n��:\n");
	ch_3=getchar();
	getchar();
	while(ch_3!='y'&&ch_3!='n')
	{
		printf("\t����������������룺\n\n") ;
		ch_3=getchar();
		getchar();
	}
	if(ch_3=='y')
	{
		num_mod2(head,m,n);
	}
}
void num_mod2(struct node *head,int m,int n)        
{
	struct node *p=head;
	int i=1;
	while(p!=NULL && i<m)
	{
		p=p->next;
		i++;
	}
	p->num=n;
	printf("\t�޸ĳɹ���\n\n");
}

void week_mod(struct node *head,int m,char nmod[])
{
	char ch_3;
	num_find(head,m);
	printf("\t�Ƿ�ȷ���޸ģ���y/n��:\n");
	ch_3=getchar();
	getchar();
	while(ch_3!='y'&&ch_3!='n')
	{
		printf("\t����������������룺\n\n") ;
		ch_3=getchar();
		getchar();
	}
	if(ch_3=='y')
	{
		week_mod2(head,m,nmod);
	}
}
void week_mod2(struct node *head,int m,char nmod[])
{
	struct node *p=head;
	int i=1;
	while(p!=NULL && i<m)
	{
		p=p->next;
		i++;
	}
	strcpy(p->week,nmod);
	printf("\t�޸ĳɹ���\n\n");
}
void time_mod(struct node *head,int m,int xx)
{
	char ch_3;
	num_find(head,m);
	printf("\t�Ƿ�ȷ���޸ģ���y/n��:\n");
	ch_3=getchar();
	getchar();
	while(ch_3!='y'&&ch_3!='n')
	{
		printf("\t����������������룺\n\n") ;
		ch_3=getchar();
		getchar();
	}
	if(ch_3=='y')
	{
		time_mod2(head,m,xx);
	}
}
void time_mod2(struct node *head,int m,int xx)
{
	struct node *p=head;
	int i=1;
	while(p!=NULL && i<m)
	{
		p=p->next;
		i++;
	}
	p->time=xx;
	printf("\t�޸ĳɹ���\n\n");
}
void major_mod(struct node *head,int m,char nmod[])
{
	
	char ch_3;
	num_find(head,m);
	printf("\t�Ƿ�ȷ���޸ģ���y/n��:\n");
	ch_3=getchar();
	getchar();
	while(ch_3!='y'&&ch_3!='n')
	{
		printf("\t����������������룺\n\n") ;
		ch_3=getchar();
		getchar();
	}
	if(ch_3=='y')
	{
		major_mod2(head,m,nmod);
	}
}
void major_mod2(struct node *head,int m,char nmod[])
{
	struct node *p=head;
	int i=1;
	while(p!=NULL && i<m)
	{
		p=p->next;
		i++;
	}
	strcpy(p->major,nmod);
	printf("\t�޸ĳɹ���\n\n");
}
void lt_mod(struct node *head,int m,char nmod[],char nname[])
{
	char ch_3;
	num_find(head,m);
	printf("\t�Ƿ�ȷ���޸ģ���y/n��:\n");
	ch_3=getchar();
	getchar();
	while(ch_3!='y'&&ch_3!='n')
	{
		printf("\t����������������룺\n\n") ;
		ch_3=getchar();
		getchar();
	}
	if(ch_3=='y')
	{
		lt_mod2(head,m,nmod,nname);
	}
}
void lt_mod2(struct node *head,int m,char nmod[],char nname[])
{
	struct node *p=head;
	int i=1;
	while(p!=NULL && i<m)
	{
		p=p->next;
		i++;
	}
	strcpy(p->lesson,nmod);
	strcpy(p->teacher,nname);
	printf("\t�޸ĳɹ���\n\n");
}
/********************************************************************************************************/
void sort(struct node *head)
{
	struct node *p;
	int w;
	printf("\t����ѡ��Ҫ�������Ŀ��\n");
	printf("\t    1.����������\n");
	printf("\t    2.����������\n");
	scanf("%d",&w);
	getchar();
	while(w!=1 && w!=2)
	{
		printf("ѡ�����������ѡ��\n");
		scanf("%d",&w);
		getchar();
	}
	if(w==1)
	{
		p=sort_num(head);
		printf("\t �����������Ϊ��\n\n");
		print(p);
	}
	else
	{
		p=sort_week(head);
		printf("\t �����������Ϊ��\n\n");
		print(p);
	}
}
struct node *sort_num(struct node *head)     //��������   ѡ����뷨 ���� 
{
	struct node *newhead;
	struct node *newtail;
	struct node *pminbefore,*pmin,*p;
	newhead=NULL;
	while(head!=NULL)
	{
		for(p=head,pmin=head;p->next!=NULL;p=p->next)
		{
			if(p->next->num<pmin->num)
			{
				pminbefore=p;
				pmin=p->next;
			}
		}
		if(newhead==NULL)
		{
			newhead=pmin;
			newtail=pmin;
		}
		else
		{
			newtail->next=pmin;
			newtail=pmin;
		}
		if(head==pmin)
		{
			head=head->next;
		}
		else
		{
			pminbefore->next=pmin->next;
		}
	}
	if(newhead!=NULL)
	{
		newtail->next=NULL;
	}
	head=newhead;
	return head;
}

struct node *sort_week(struct node *head)
{
	struct node *p=head,*p1=NULL,*p2=NULL,*p3=NULL,*p4=NULL;
	struct node *p5=NULL; 
	struct node *head1=NULL,*head2=NULL,*head3=NULL,*head4=NULL;
	struct node *head5=NULL,*headx=NULL;
	if(p==NULL)
	{
		printf("����Ϊ�գ�����¼�����ݣ�\n");
		menu();
	}
	else
	{
		while(p!=NULL)
		{
			if(!strcmp(p->week,"����һ"))
			{
				if(head1==NULL)
					head1=p;
				else
					p1->next=p;
				p1=p;	
			}
			if(!strcmp(p->week,"���ڶ�"))
			{
				if(head2==NULL)
					head2=p;
				else
					p2->next=p;
				p2=p;
			}
			if(!strcmp(p->week,"������"))
			{
				if(head3==NULL)
					head3=p;
				else
					p3->next=p;
				p3=p;
			}
			if(!strcmp(p->week,"������"))
			{
				if(head4==NULL)
					head4=p;
				else
					p4->next=p;
				p4=p;
			}
			if(!strcmp(p->week,"������"))
			{
				if(head5==NULL)
					head5=p;
				else
					p5->next=p;
				p5=p;
			}
			p=p->next;
		}
		p1->next=NULL;
		p2->next=NULL;
		p3->next=NULL;
		p4->next=NULL;
		p5->next=NULL;
		head1=sort_week1(head1);     //���Լ򻯡������������������������������������� 
		head2=sort_week1(head2);
		link(head1,head2);
		head3=sort_week1(head3);
		link(head1,head3);
		head4=sort_week1(head4);
		link(head1,head4);
		head5=sort_week1(head5);
		link(head1,head5);
	}
	return head1;
}

void  link(struct node *head1,struct node *head2)     //�������Ӻ��� 
{
	struct node *p=head1,*p2=head2;
	while(p->next!=NULL)
	{
		p=p->next;
	}
	p->next=head2;
	while(p2->next!=NULL)
	{
		p2=p2->next;
	}
	p2->next==NULL;
}
struct node *sort_week1(struct node *head)        
{
	struct node *newhead;
	struct node *newtail;
	struct node *pminbefore,*pmin,*p;
	newhead=NULL;
	while(head!=NULL)
	{
		for(p=head,pmin=head;p->next!=NULL;p=p->next)
		{
			if(p->next->time<pmin->time)
			{
				pminbefore=p;
				pmin=p->next;
			}
		}
		if(newhead==NULL)
		{
			newhead=pmin;
			newtail=pmin;
		}
		else
		{
			newtail->next=pmin;
			newtail=pmin;
		}
		if(head==pmin)
		{
			head=head->next;
		}
		else
		{
			pminbefore->next=pmin->next;
		}
	}
	if(newhead!=NULL)
	{
		newtail->next=NULL;
	}
	head=newhead;
	return head;
}
//������������������������������������������������������������������������������������������������ 
void menu()
{
	int x;
	char ch_2;
	struct node *head,*px; 
	do
	{
		printf("*****************************************\n");
		printf("     1.������Ϣ¼��\n") ;
		printf("     2.���������Ϣ\n");
		printf("     3.���ҽ�����Ϣ\n");
		printf("     4.ɾ��������Ϣ\n");
		printf("     5.�޸Ľ�����Ϣ\n");
		printf("     6.���������Ϣ\n");
		printf("     7.������Ϣ����\n");
		printf("     0.�˳�    \n");
		printf("*****************************************\n");
		scanf("%d",&x);
		getchar();
		switch(x)
		{
			case 1: printf("��Ϣ¼�뽫�Ḳ����ǰ����Ϣ���Ƿ����(y/n):\n") ;
					scanf("%c",&ch_2);
					getchar();
				    while(ch_2!='y' && ch_2!='n')            
					{
						printf("\t����������������룺\n\n") ;
						ch_2=getchar();
						getchar();
					}
					if(ch_2=='y')
					{
						head=creat();
						printf("¼�����ϢΪ��\n");
						print(head);
						judge(head) ;
					}
					else
						menu();
					break;
			case 2: printf("\t��������Ϊ��\n\n");
					head=load();
					print(head);
					printf("��������Ҫ��ӵ���Ϣ:\n\n");   //���֮ǰ���Լ��Ҫ��ӵ������Ƿ���ڣ�����������  ���뺯�� 
					insert(head,num());          //����������Ϣ 
					printf("����������Ϊ��\n\n");
					print(head);                       
					judge(head);
					break;
			case 3: head=load();
					printf("��ѡ����Ҫ��Ѱ��Ŀ��\n\n");
					find(head);
					break;
			case 4: head=load();
					print(head);
					printf("����ѡ��Ҫ���������ͣ�\n\n");
					dele(head) ;
					printf("ɾ���������Ϊ��\n\n");
					print(head);
					judge(head);
					break;
			case 5:head=load();
					print(head);
					mod(head);
					judge(head);
					break;
			case 6:
					head=load();
					print(head)	;
					printf("\t�Ƿ����������(y/n)?\n\n");
					scanf("%c",&ch_2);
					getchar();
				    while(ch_2!='y' && ch_2!='n')            
					{
						printf("\t����������������룺\n\n") ;
						ch_2=getchar();
						getchar();
					}
					if(ch_2=='y')
					{
						menu();   //��������Ϣ�����ļ� 
						break;
					}
					else 
						x=0;
			case 7: head=load();
					sort(head);
					break;			
			case 0:
					printf("\t��ӭʹ�á����������ټ���������\n");
					break;											
		}
	}while(x!=0);
}
//�������������������������������������������������������������������������������������������������������� 
int main()
{
	char name[30],name_2[30];
	char password[30],password_2[30],np[70];
	char ch_1;
	menu();
	return 0;
}
//������������������������������������������������������������������������������������������������������ 
