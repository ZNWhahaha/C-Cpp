#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct student
{	char xuehao[10];
	char name[20];
	int sore[3];
	struct student *next;
};
int iCount;
struct student *input()
{	int i;
	struct student *pHead=NULL,*pEnd,*pNew;
	pNew=pEnd=(struct student *)malloc(sizeof(struct student));
	scanf("%s",pNew->xuehao);
	scanf("%s",pNew->name);
	for(i=0;i<3;i++)
		scanf("%d",pNew->sore[i]);
	while(pNew->xuehao!=0)
	{	iCount++;
		if(ICount==1)
		{	pNew->next=pHead;
			pEnd=pNew;
			pHead=pNew;
		}
		else
		{	pNew->next=NULL;
			pEnd->next=pNew;
			pEnd=pNew;
	
		}
	}
}
