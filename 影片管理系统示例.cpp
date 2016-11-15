#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LEN sizeof(struct Movie)
typedef struct Movie
{	int id;
	char name[20];
	char director[10];
	char actor[20];
	char date[10];
	float score;
	struct move *next;	
}Film;
void insertFilm()
{	Film *p,*q=*head;//更改代码，使二级指针变一级指针 
	p=(Film*)malloc(LEN);
	p->id=film_id;
	printf("================================================\n");
	printf("			    ****添加影片信息****			\n");
	printf("================================================\n");
	printf("		分配给该影片的编号是:%d\n",film_id);
	printf("		输入影片名称：");
	scanf("%s",p->name);
	printf("		输入影片导演：");
	scanf("%s",p->director);
	printf("		输入影片主演：");
	scanf("%s",p->actor);
	printf("		输入影片上映时间：");
	scanf("%s",p->date);
	printf("		输入影片评分：");
	scanf("%f",p->score);
	printf("		输入完成		\n"); 
	p->next=NULL;
	if(!q)
		*head=p;
	else
	{	while(q->next)
			q=q->next;
		q->next=p;
	}	
}

int main(void)
{	int x,flag=1,film_id=1;
	struct Movie *head;
	while(1)
		{
		printf("		==========影片信息信息管理系统==========\n");
		printf("		*          	1-录入影片信息             *\n");
		printf("		*           2-查询影片信息             *\n");
		printf("		*        	3-修改影片信息             *\n");
		printf("		*        	4-删除影片信息             *\n");
		printf("		*           5-显示所有影片             *\n");
		printf("		*        	6-	影片总数               *\n");
		printf("		*        	7-  退出程序               *\n");
		printf("		========================================\n");
		printf("输入要执行的操作：");
		scanf("%d",&x);
		switch(x)
		{
			case 1:
			{	insertFilm();
				film_id++;
				break;
			}
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
