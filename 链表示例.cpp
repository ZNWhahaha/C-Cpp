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
	printf("������ѧ����������ѧ�ţ�\n");
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
	printf("**********����������%d��ѧ��**********\n",iCount);
	pTemp=pHead;
	while(pTemp!=NULL)
	{	printf("��%d��ѧ���ǣ�\n",iIndex);
		printf("������%s\n",pTemp->cName);
		printf("ѧ�ţ�%d\n\n",pTemp->iNumber);
		pTemp=pTemp->next;
		iIndex++;
	}
} 
struct Student *Insert(struct Student *pHead, int number)
{	struct Student *p=pHead,*pNew;
	while(p&&p->iNumber!=number)
		p=p->next;
	printf("����ѧ����������ѧ�ţ�\n");
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
	printf("------ɾ����%d��ѧ��------\n",iIndex);
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
	printf("����Ҫ�����ѧ������ţ�\n");
	scanf("%d",&n);
	pHead=Insert(pHead,n);
	print(pHead);
	printf("����Ҫɾ����ѧ������ţ�\n");
	scanf("%d",&n);
	Delete(pHead,n);
	print(pHead);
}
 
