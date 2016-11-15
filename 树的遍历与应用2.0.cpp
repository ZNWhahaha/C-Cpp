#include<stdio.h>
#include<stdlib.h>
#define MAX 20 

typedef struct Node{		//���ڶ������Ķ��� 
	char data;
	struct Node *Lchild;
	struct Node *Rchild;
}BiTNode,* BiTree;

typedef struct{		//�洢ջ�Ķ��� 
	BiTree data[MAX];
	int top;
}SeqStack;

BiTree Creat(){	//������չ����������������������� 
	BiTree r;
	char ch;
	ch = getchar();
	if(ch == '#')
		return NULL;
	else{
		r = (BiTree )malloc(sizeof(BiTNode));
		r->Lchild = Creat();
		r->Rchild = Creat();
		r->data = ch;
		return r;
	} 
}

SeqStack * InitStack(SeqStack *s){		//�ÿ�ջ����
	s = (SeqStack *)malloc(sizeof(SeqStack));
	s->top = -1;
	return s; 
} 

int IsEmpty(SeqStack *s){	//�п�ջ���� 
	if(s->top = -1)
		return 1;
	else
		return 0;
}

int Push(SeqStack *s,BiTree x){	//��ջ���� 
	if(s->top == MAX -1)
		return 0;
	else{
		s->top++;
		s->data[s->top] = x;
		return 1;
	}
}

int Pop(SeqStack *s,BiTree *x){	//	��ջ���� 
	if(IsEmpty(s))
		return 0;
	else{
		*x = s->data[s->top];
		s->top--;
		return 1;
	}
}

void  PreOder1(BiTree r){		//�ǵݹ�������������� 
	SeqStack *s;
	BiTree p;
	InitStack(s);
	p = r;
	while(p != NULL || !IsEmpty(s)){
		while(p != NULL){
			printf("%c",p->data);
			Push(s,p);
			p = p->Lchild;
			if(!IsEmpty(s)){
				Pop(s,&p);
				p = p->Rchild;
			}
		}	
	}
}
void InOder1(BiTree r){			//�ǵݹ�������������� 
	SeqStack *S;
	BiTree p;
	InitStack(S);
	p = r;
	while(p != NULL || !IsEmpty(S)){
		while(p!=NULL){
			Push(S,p);
			p = p->Lchild;
		}
		if(!IsEmpty(S)){
			Pop(S,&p);
			printf("%c\n",p->data);
			p = p->Rchild;
		}
	}
}

void PreOder(BiTree r){		//�������ĵݹ�ǰ����� 
	if(r){
		printf("%c",r->data);
		PreOder(r->Lchild);
		PreOder(r->Rchild);
	}
}

void InOder(BiTree r){		//�������ĵݹ�������� 
	if(r){
		InOder(r->Lchild);
		printf("%c",r->data);
		InOder(r->Rchild);
	}
} 

void PostOder(BiTree r){
	if(r){
		PostOder(r->Lchild);
		PostOder(r->Rchild);
		printf("%c",r->data);
	}
} 

void InOrder(BiTree r){		//������������������Ҷ�ӽڵ㣻
	if(r){
		InOrder(r->Lchild);
		if(r->Lchild == NULL && r->Rchild == NULL)
			printf("%c",r->data);
		InOrder(r->Rchild);
	} 
}

int leafNumber0(BiTree r){		//ͳ��Ҷ�ӽڵ�ĸ���
	int nl,nr;
	if(r == NULL)
		return 0;
	if((r->Lchild == NULL) && (r->Rchild == NULL))
		return 1;
	nl = leafNumber0(r->Lchild);
	nr = leafNumber0(r->Rchild);
	return nl+nr; 
}
int n1 = 0,n2 = 0;
int leafNumber1(BiTree r){		//����ȫ�ֱ�������������У���Ϊ1�Ľ��ĸ��� 
	if(r == NULL)
		return 0;
	if(((r->Lchild == NULL) && (r->Rchild != NULL)) || 
				((r->Lchild != NULL) && (r->Rchild == NULL)))
		n1++;
	leafNumber1(r->Lchild);
	leafNumber1(r->Rchild);
} 
int leafNumber2(BiTree r){		//����ȫ�ֱ�������������У���Ϊ2�Ľ��ĸ���
	if(r == NULL)
		return 0;
	if((r->Lchild != NULL) && (r->Rchild != NULL))
		n2++;
	leafNumber2(r->Lchild);
	leafNumber2(r->Rchild); 
}
int main(void){
	BiTree r;
	int n0;
	r = Creat();
/*	PreOder(r);						�ݹ������ӡ������ 
	printf("\n");		
	InOder(r);						�ݹ������ӡ������ 
	printf("\n");
	PostOder(r);					�ݹ�����ӡ������ 		*/
	 
/*	n0 = leafNumber0(r);			���Ҷ�ӽڵ�ĸ��� 
	leafNumber1(r);					�����Ϊ1�Ľڵ�ĸ��� 
	leafNumber2(r);					�����Ϊ2�Ľڵ�ĸ���	
	printf("%d %d %d\n",n0,n1,n2);
	InOrder(r);						���Ҷ�ӽڵ�*/ 
	
	PreOder1(r);
	printf("\n");
	InOder1(r);
}
