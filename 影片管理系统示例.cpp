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
{	Film *p,*q=*head;//���Ĵ��룬ʹ����ָ���һ��ָ�� 
	p=(Film*)malloc(LEN);
	p->id=film_id;
	printf("================================================\n");
	printf("			    ****���ӰƬ��Ϣ****			\n");
	printf("================================================\n");
	printf("		�������ӰƬ�ı����:%d\n",film_id);
	printf("		����ӰƬ���ƣ�");
	scanf("%s",p->name);
	printf("		����ӰƬ���ݣ�");
	scanf("%s",p->director);
	printf("		����ӰƬ���ݣ�");
	scanf("%s",p->actor);
	printf("		����ӰƬ��ӳʱ�䣺");
	scanf("%s",p->date);
	printf("		����ӰƬ���֣�");
	scanf("%f",p->score);
	printf("		�������		\n"); 
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
		printf("		==========ӰƬ��Ϣ��Ϣ����ϵͳ==========\n");
		printf("		*          	1-¼��ӰƬ��Ϣ             *\n");
		printf("		*           2-��ѯӰƬ��Ϣ             *\n");
		printf("		*        	3-�޸�ӰƬ��Ϣ             *\n");
		printf("		*        	4-ɾ��ӰƬ��Ϣ             *\n");
		printf("		*           5-��ʾ����ӰƬ             *\n");
		printf("		*        	6-	ӰƬ����               *\n");
		printf("		*        	7-  �˳�����               *\n");
		printf("		========================================\n");
		printf("����Ҫִ�еĲ�����");
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
