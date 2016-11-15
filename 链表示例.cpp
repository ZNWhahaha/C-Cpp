#include<stdio.h>
#include<stdlib.h>
struct Student
{	char cName[20];
	int iNumber;
	struct Student *next;
};
int iCount;
struct Student *Create()
{	struct Student *pHead=NULL;
	struct Student *pEnd,*pNew;
	iCount=0;
	pEnd=pNew=(struct Student *)malloc(sizeof(struct Student));
	printf("请输入学生的姓名及学号：\n");
	scanf("%s",pNew->cName);
	scanf("%d",&pNew->iNumber);
	while(pNew->iNumber!=0)
	{	iCount++;
		if(iCount==1)
		{	pNew->next=pHead;
			pEnd=pNew;
			pHead=pNew;
		}
		else
		{	pNew->next=NULL;
			pEnd->next=pNew;
			pEnd=pNew;
		}
		pNew=(struct Student *)malloc(sizeof(struct Student));
		scanf("%s",pNew->cName);
		scanf("%d",&pNew->iNumber);
	}
	free(pNew);
	return pHead;
}
void print(struct Student *pHead)
{	struct Student *pTemp;
	int iIndex=1;
	printf("**********本名单中有%d个学生**********\n",iCount);
	pTemp=pHead;
	while(pTemp!=NULL)
	{	printf("第%d个学生是：\n",iIndex);
		printf("姓名：%s\n",pTemp->cName);
		printf("学号：%d\n\n",pTemp->iNumber);
		pTemp=pTemp->next;
		iIndex++;
	}
} 
struct Student *Insert(struct Student *pHead, int number)
{	struct Student *p=pHead,*pNew;
	while(p&&p->iNumber!=number)
		p=p->next;
	printf("输入学生的姓名和学号：\n");
	pNew=(struct Student *)malloc(sizeof(struct Student));
	scanf("%s",pNew->cName);
	scanf("%d",&pNew->iNumber);
	pNew->next=p->next;
	p->next=pNew;
	iCount++;
	return pHead;
}
void Delete(struct Student *pHead,int iIndex)
{	int i;
	struct Student *pTemp;
	struct Student *pPre;
	pTemp=pHead;
	pPre=pTemp;
	printf("------删除第%d个学生------\n",iIndex);
	for(i=1;i<iIndex;i++)
	{	pPre=pTemp;
		pTemp=pTemp->next;
	}
	pPre->next=pTemp->next;
	free(pTemp);
	iCount--;
} 
int main(void)
{	struct Student *pHead;
	int n,m;
	pHead=Create();
	print(pHead);
	printf("输入要插入的学生的序号：\n");
	scanf("%d",&n);
	pHead=Insert(pHead,n);
	print(pHead);
	printf("输入要删除的学生的序号；\n");
	scanf("%d",&n);
	Delete(pHead,n);
	print(pHead);
}
 
