#include<stdio.h> 
#include<stdlib.h>
#include<string.h>

#define LEN sizeof(struct node)
#define PRINT "%5d%10s%  -5d%8s%10s%6s%8s\n",p->num,p->week,p->time,p->major,p->lesson,p->teacher,p->room
#define PRINT_1 "教室序号   星期   课节数    专业      课名      老师     教室      \n"
	struct node* num(void) ;      //链表结点信息->38
	struct node *creat(void);     //创建链表函数->
	void print(struct node *head);    //打印链表函数-> 
	void insert(struct node *p,struct node *px);    //将新结点接到链表尾部函数->
	void fprint(struct node *head) ;             //将链表的数据导入文件中的函数->
	struct node * load(void) ;       //将文件中的数据取出存入链表中的函数->
	void find_1();                 //查找选项 函数->
	void menu();                   //菜单函数-> 
	void num_find(struct node *head,int h);       //按序号查找数据函数 
	void week_find(struct node *head,char s[]);    //按星期查找数据函数 
	void teacher_find(struct node *head, char s[] ); //按老师查找数据函数 
	void room_find(struct node *head,char s[]);       //按教室查找数据函数 
	void num_dele(struct node *head,int n);         //按教室排号删除
	void room_dele(struct node *head,char arr[]) ;   //按教室号删除 
	void num_mod(struct node *head,int m,int n);     
	void num_mod2(struct node *head,int m,int n);          //修改教室序号函数 
	void week_mod(struct node *head,int m,char nmod[]);
	void week_mod2(struct node *head,int m,char nmod[]);    //修改星期函数   
	void time_mod(struct node *head,int oo,int xx);
	void time_mod2(struct node *head,int oo,int xx);        //修改上课时间函数
	void major_mod(struct node *head,int m,char nmod[]);
	void major_mod2(struct node *head,int m,char nmod[]);   //修改专业函数 
	void lt_mod(struct node *head,int m,char nmod[],char nname[]);
	void lt_mod2(struct node *head,int m,char nmod[],char nname[]);     //老课程修改函数 
	struct node *sort_num(struct node *head);     //链表排序   选择插入法 排序 
	struct node *sort_week(struct node *head);
	struct node *sort_week1(struct node *head);
	void link(struct node *head1,struct node *head2);
struct node         //结点信息 
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
struct node* num(void)        //封装链表结点录入信息 
{
	int w;
	struct node *head,*p1;
	head=p1=(struct node *)malloc(LEN) ;
	printf("请输入教室序号：\n");
	scanf("%d",&p1->num);
	pp:	printf("请选择你要输入的星期：\n");
	printf("   1.星期一\n");
	printf("   2.星期二\n");
	printf("   3.星期三\n");
	printf("   4.星期四\n");
	printf("   5.星期五\n");
	printf("   6.星期六\n");
	printf("   7.星期日\n");
	printf("请选择：\n");
	scanf("%d",&w);
	getchar();
	if(w==1)
	{
		strcpy(p1->week,"星期一");
	}
	else if(w==2)
	{
		strcpy(p1->week,"星期二");
	}
	else if(w==3)
	{
		strcpy(p1->week,"星期三");
	}
	else if(w==4)
	{
		strcpy(p1->week,"星期四");
	}
	else if(w==5)
	{
		strcpy(p1->week,"星期五");
	}
	else if(w==6)
	{
		strcpy(p1->week,"星期六");
	}
	else if(w==7)
	{
		strcpy(p1->week,"星期日");
	}
	else if(w>7||w<1)
	{
		printf("选择错误  请重新选择：\n");
		goto pp;
	}
	printf("请输入上课时间（七点到十点为  1）:\n");
	scanf("%d",&p1->time);
	getchar();
	printf("请输入专业（如软件工程）:\n");
	scanf("%s",p1->major);
	getchar();
	printf("请输入课程（如c语言）:\n");
	scanf("%s",p1->lesson);
	getchar();
	printf("请输入老师(如张三):\n");
	scanf("%s",p1->teacher);
	getchar();
	printf("请输入教室号（如FZ155）:\n");
	scanf("%s",p1->room);
	getchar();
	p1->next=NULL;
	return head;
}
/************************************************************************************************/ 
struct node *creat(void)     //创建一个链表  
{
	struct node *head=NULL,*p1=NULL,*p2=NULL;
	head=p1=p2=num() ;
	while(p1->num!=0)      //每个节点往上个结点接 
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
/*******************************输出函数*********************************/ 
void print(struct node *head)
{
	struct node *p;
	p=head;
	if(p==NULL)
	{
		printf("此链表为空！");
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
		printf("文件打开失败！\n");
		exit(0);
	}
	else
	{
		while(p)
		{
			fprintf(fp,"%d %s %d %s %s %s %s ",p->num,p->week,p->time,p->major,p->lesson,p->teacher,p->room);
			p=p->next; 
		}
		printf("保存成功！！！\n");
		fclose(fp);
	}
}
/************************************************************************************************/
void judge(struct node *head)             //判断是否保存函数 
{
	char ch_2;
	printf("是否保存信息？（y/n)");
	ch_2=getchar();
	getchar();
	while(ch_2!='y'&&ch_2!='n')
	{
		printf("\t输入错误，请重新输入：\n\n") ;
		ch_2=getchar();
		getchar();
	}
	if(ch_2=='y')
	{
		fprint(head);    //将链表信息存入文件 
	}
	else
	{
		menu();
	}
}

/****************************************************************************************/
struct node * load(void)        //将文件中的数据取出存入链表中 
{
	FILE *fp;
	struct node *head,*p1,*p2;
	head=p1=p2=NULL;
	if((fp=fopen("data.txt","r"))==NULL)
	{
		printf("文件为空，请先录入数据，谢谢合作！\n\n");
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
void find(struct node *head)                 //查找选项 
{
	int k,h;
	char a[15] ;
	printf("****************************************\n");
	printf("        1.按序号查找\n");
	printf("        2.按星期查找\n");
	printf("        3.按老师查找\n");
	printf("        4.按教室查找\n");
	printf("****************************************\n");
	printf("      请输入序号：\n");
	scanf("%d",&k);
	getchar();
	while(k<1||k>4)
	{
		printf("输入错误！请重新输入：\n");
		scanf("%d",&k);
		getchar();
	}
	if(k>=1&&k<=4)
	{
		switch(k)
		{
			case 1:
				printf("请你输入你要查找的教室序号:\n");
				scanf("%d",&h);
				getchar();
				num_find(head,h);
				break;
			case 2:
				printf("请你输入要查询的星期:（例 星期一 ）\n");
				gets(a);
				week_find(head,a);
				break;
			case 3:
				printf("请你输入要查找的老师：(例 张三 )\n") ;
				gets(a);
				teacher_find(head,a);
				break;
			case 4:
				printf("请你输入要查找的教室：(例 FZ155)\n");
				gets(a);
				room_find(head,a);
				break;			
		}
	}
}
void num_find(struct node *head,int h)       //按序号查找教室函数 
{
	struct node *p=head;
	int i=1;
	if(p==NULL)
	{
		printf("链表为空！请先导入数据！\n");
		p=load();
	}
	else
	{
		while(p!=NULL && i<h)
		{
			p=p->next;
			i++;
		}
		printf("第%d教室的数据为:\n\n",i);
		printf(PRINT_1) ;
		printf(PRINT);
	}
}
void week_find(struct node *head,char s[])     //按星期查找数据函数 
{
	struct node *p=head;
	int i=0,flag=1;
	if(p==NULL)
	{
		printf("链表为空！请先导入数据！\n");
		p=load();
	}
	else
	{
		for(i=0;i<=maxlen;i++)      // maxlen是链表的长度 
		{
			while(p!=NULL && strcmp(p->week,s))   
			{
				p=p->next;
			} 
			if(p==NULL) 
			{
				printf("未找到%s的数据\n\n",s);
				break;
			}
			else if(flag==1)
			{
				printf("你要查询的%s的数据为:\n",s);
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
void teacher_find(struct node *head, char s[])          //按老师查找函数 
{
	struct node *p=head;
	int i=0,flag=1;
	if(p==NULL)
	{
		printf("链表为空！请先导入数据！\n");
		p=load();
	}
	else
	{
		for(i=0;i<=maxlen;i++)                     // maxlen是链表的长度 
		{
			while(p!=NULL && strcmp(p->teacher,s))    
			{
				p=p->next;
			} 
			if(p==NULL) 
			{
				printf("未找到%s的数据\n\n",s);
				break;
			}
			else if(flag==1)
			{
				printf("你要查询的%s的数据为:\n",s);
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

 void room_find(struct node *head,char s[])       //尝试封装！！！！！！！！！！！！！！！！！ 
 {
	struct node *p=head;
	int i=0,flag=1;
	if(p==NULL)
	{
		printf("链表为空！请先导入数据！\n");
		p=load();
	}
	else
	{
		for(i=0;i<=maxlen;i++)      // maxlen是链表的长度 
		{
			while(p!=NULL && strcmp(p->room,s))     
			{
				p=p->next;
			} 
			if(p==NULL) 
			{
				printf("未找到%s的数据\n\n",s);
				break;
			}
			else if(flag==1)
			{
				printf("你要查询的%s的数据为:\n",s);
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
	printf("\t1.教室序号！\n");
	printf("\t2.教室号\n");
	scanf("%d",&dele_x);
	getchar();
	while(dele_x!=1 && dele_x!=2)
	{
		printf("输入错误,请重新输入：\n");
		scanf("%d",&dele_x);
		getchar();
	}
	if(dele_x==1)
	{
		printf("请输入要删除的教室序号：\n");
		scanf("%d",&m);
		getchar();
		num_dele(head,m);
		maxlen--;
	}
	else if(dele_x==2)
	{
		printf("请输入要删除的教室号：(例 FF155)\n");
		gets(char_x);
		room_dele(head,char_x);
		maxlen--;
	}
}

void num_dele(struct node *head,int n)       //按教室序号删除的函数 
{
	struct node *p=head,*p2=NULL;
	int i=1;
	if(p==NULL) 
	{
		printf("链表为空！请先导入数据！\n");
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
			printf("删除的位置不存在！\n");
		}
		else
		{
			p2->next=p->next;
			free(p);
			printf("删除成功！\n\n");
		}
	}
}

void room_dele(struct node *head,char s[])      //按教室号删除的函数 
{
	struct node *p=head,*p2=NULL;
	int i=0;
	if(p==NULL) 
	{
		printf("链表为空！请先导入数据！\n");
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
				printf("未找到%s的数据\n\n",s);
			}
			else
			{
				p2->next=p->next;
				free(p);
				printf("删除成功！\n\n");
			}
	}
}
void mod(struct node *head)        //修改结点信息的函数 
{
	struct node *p=head;
	char arr[20];
	char nname[20],nmod[20];
	int xx ,oo;
	printf("请你输入要修改的项目名：\n\n");
	gets(arr);
	if(!strcmp("教室序号",arr))
	{
		printf("请输入你要修改的教室序号和修改为的教室序号：\n");
		scanf("%d%d",&oo,&xx);
		getchar();
		num_mod(head,oo,xx);
		printf("修改后的数据为：\n\n");
		print(head);
	}
	else if(!strcmp("星期",arr)) 
	{
		printf("请你输入要修改星期的教室序号：\n");
		scanf("%d",&oo);
		getchar();
		printf("请你输入要修改后的星期: \n");
		gets(nmod);
		week_mod(head,oo,nmod);
		printf("修改后的数据为：\n\n");
		print(head);
	}
	else if(!strcmp("上课时间",arr))
	{
		printf("请你输入要修改上课时间的教室序号：\n");
		scanf("%d",&oo);
		getchar();
		printf("请你输入要修改后的上课时间: \n");
		scanf("%d",&xx) ;
		getchar();
		time_mod(head,oo,xx);
		printf("修改后的数据为：\n\n");
		print(head);
	}
	else if(!strcmp("专业名称",arr))
	{
		printf("请你输入要修改上课时间的教室序号：\n");
		scanf("%d",&oo);
		getchar();
		printf("请你输入要修改后的专业名称:\n");
		gets(nmod);
		week_mod(head,oo,nmod);
		printf("修改后的数据为：\n\n");
		print(head);
	}
	else if(!strcmp("课程名称",arr)||!strcmp("老师姓名",arr))
	{
		printf("请你输入要修改上课时间的教室序号：\n");
		scanf("%d",&oo);
		getchar();
		printf("请你输入要修改后的课程名称:\n");
		gets(nmod);
		printf("请你输入要修改后的老师姓名:\n") ;
		gets(nname) ;
		lt_mod(head,oo,nmod,nname);
		printf("修改后的数据为：\n\n");
		print(head);
	}
	else
	{
		printf("输入错误！\n");
	}
}
/*************************************************************************************************/
void num_mod(struct node *head,int m,int n)
{
	char ch_3;
	num_find(head,m);
	printf("\t是否确定修改？（y/n）:\n");
	ch_3=getchar();
	getchar();
	while(ch_3!='y'&&ch_3!='n')
	{
		printf("\t输入错误，请重新输入：\n\n") ;
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
	printf("\t修改成功！\n\n");
}

void week_mod(struct node *head,int m,char nmod[])
{
	char ch_3;
	num_find(head,m);
	printf("\t是否确定修改？（y/n）:\n");
	ch_3=getchar();
	getchar();
	while(ch_3!='y'&&ch_3!='n')
	{
		printf("\t输入错误，请重新输入：\n\n") ;
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
	printf("\t修改成功！\n\n");
}
void time_mod(struct node *head,int m,int xx)
{
	char ch_3;
	num_find(head,m);
	printf("\t是否确定修改？（y/n）:\n");
	ch_3=getchar();
	getchar();
	while(ch_3!='y'&&ch_3!='n')
	{
		printf("\t输入错误，请重新输入：\n\n") ;
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
	printf("\t修改成功！\n\n");
}
void major_mod(struct node *head,int m,char nmod[])
{
	
	char ch_3;
	num_find(head,m);
	printf("\t是否确定修改？（y/n）:\n");
	ch_3=getchar();
	getchar();
	while(ch_3!='y'&&ch_3!='n')
	{
		printf("\t输入错误，请重新输入：\n\n") ;
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
	printf("\t修改成功！\n\n");
}
void lt_mod(struct node *head,int m,char nmod[],char nname[])
{
	char ch_3;
	num_find(head,m);
	printf("\t是否确定修改？（y/n）:\n");
	ch_3=getchar();
	getchar();
	while(ch_3!='y'&&ch_3!='n')
	{
		printf("\t输入错误，请重新输入：\n\n") ;
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
	printf("\t修改成功！\n\n");
}
/********************************************************************************************************/
void sort(struct node *head)
{
	struct node *p;
	int w;
	printf("\t请你选择要排序的项目：\n");
	printf("\t    1.按教室排序\n");
	printf("\t    2.按星期排序\n");
	scanf("%d",&w);
	getchar();
	while(w!=1 && w!=2)
	{
		printf("选择错误！请重新选择：\n");
		scanf("%d",&w);
		getchar();
	}
	if(w==1)
	{
		p=sort_num(head);
		printf("\t 已排序的数据为：\n\n");
		print(p);
	}
	else
	{
		p=sort_week(head);
		printf("\t 已排序的数据为：\n\n");
		print(p);
	}
}
struct node *sort_num(struct node *head)     //链表排序   选择插入法 排序 
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
		printf("链表为空！请先录入数据！\n");
		menu();
	}
	else
	{
		while(p!=NULL)
		{
			if(!strcmp(p->week,"星期一"))
			{
				if(head1==NULL)
					head1=p;
				else
					p1->next=p;
				p1=p;	
			}
			if(!strcmp(p->week,"星期二"))
			{
				if(head2==NULL)
					head2=p;
				else
					p2->next=p;
				p2=p;
			}
			if(!strcmp(p->week,"星期三"))
			{
				if(head3==NULL)
					head3=p;
				else
					p3->next=p;
				p3=p;
			}
			if(!strcmp(p->week,"星期四"))
			{
				if(head4==NULL)
					head4=p;
				else
					p4->next=p;
				p4=p;
			}
			if(!strcmp(p->week,"星期五"))
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
		head1=sort_week1(head1);     //尝试简化》》》》》》》》》》》》》》》》》》》 
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

void  link(struct node *head1,struct node *head2)     //链表链接函数 
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
//》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》 
void menu()
{
	int x;
	char ch_2;
	struct node *head,*px; 
	do
	{
		printf("*****************************************\n");
		printf("     1.教室信息录入\n") ;
		printf("     2.增添教室信息\n");
		printf("     3.查找教室信息\n");
		printf("     4.删除教室信息\n");
		printf("     5.修改教室信息\n");
		printf("     6.浏览教室信息\n");
		printf("     7.教室信息排序\n");
		printf("     0.退出    \n");
		printf("*****************************************\n");
		scanf("%d",&x);
		getchar();
		switch(x)
		{
			case 1: printf("信息录入将会覆盖以前的信息，是否继续(y/n):\n") ;
					scanf("%c",&ch_2);
					getchar();
				    while(ch_2!='y' && ch_2!='n')            
					{
						printf("\t输入错误，请重新输入：\n\n") ;
						ch_2=getchar();
						getchar();
					}
					if(ch_2=='y')
					{
						head=creat();
						printf("录入的信息为：\n");
						print(head);
						judge(head) ;
					}
					else
						menu();
					break;
			case 2: printf("\t已有数据为：\n\n");
					head=load();
					print(head);
					printf("请输入你要添加的信息:\n\n");   //添加之前可以检查要添加的数据是否存在？？？？？？  加入函数 
					insert(head,num());          //插入链表信息 
					printf("添加完的链表为：\n\n");
					print(head);                       
					judge(head);
					break;
			case 3: head=load();
					printf("请选择你要查寻项目：\n\n");
					find(head);
					break;
			case 4: head=load();
					print(head);
					printf("请你选择要操作的类型：\n\n");
					dele(head) ;
					printf("删除完的数据为：\n\n");
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
					printf("\t是否继续操作？(y/n)?\n\n");
					scanf("%c",&ch_2);
					getchar();
				    while(ch_2!='y' && ch_2!='n')            
					{
						printf("\t输入错误，请重新输入：\n\n") ;
						ch_2=getchar();
						getchar();
					}
					if(ch_2=='y')
					{
						menu();   //将链表信息存入文件 
						break;
					}
					else 
						x=0;
			case 7: head=load();
					sort(head);
					break;			
			case 0:
					printf("\t欢迎使用。。。。。再见！！！！\n");
					break;											
		}
	}while(x!=0);
}
//》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》 
int main()
{
	char name[30],name_2[30];
	char password[30],password_2[30],np[70];
	char ch_1;
	menu();
	return 0;
}
//》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》 
