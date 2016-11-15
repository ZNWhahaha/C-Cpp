#include<stdio.h>
#include<stdlib.h>
#define MAX 20 

typedef struct Node{		//对于二叉树的定义 
	char data;
	struct Node *Lchild;
	struct Node *Rchild;
}BiTNode,* BiTree;

typedef struct{		//存储栈的定义 
	BiTree data[MAX];
	int top;
}SeqStack;

BiTree Creat(){	//采用扩展先序遍历来创建二叉树链表 
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

SeqStack * InitStack(SeqStack *s){		//置空栈操作
	s = (SeqStack *)malloc(sizeof(SeqStack));
	s->top = -1;
	return s; 
} 

int IsEmpty(SeqStack *s){	//判空栈操作 
	if(s->top = -1)
		return 1;
	else
		return 0;
}

int Push(SeqStack *s,BiTree x){	//入栈操作 
	if(s->top == MAX -1)
		return 0;
	else{
		s->top++;
		s->data[s->top] = x;
		return 1;
	}
}

int Pop(SeqStack *s,BiTree *x){	//	出栈操作 
	if(IsEmpty(s))
		return 0;
	else{
		*x = s->data[s->top];
		s->top--;
		return 1;
	}
}

void  PreOder1(BiTree r){		//非递归先序遍历二叉树 
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
void InOder1(BiTree r){			//非递归中序遍历二叉树 
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

void PreOder(BiTree r){		//二叉树的递归前序遍历 
	if(r){
		printf("%c",r->data);
		PreOder(r->Lchild);
		PreOder(r->Rchild);
	}
}

void InOder(BiTree r){		//二叉树的递归中序遍历 
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

void InOrder(BiTree r){		//中序遍历输出二叉树的叶子节点；
	if(r){
		InOrder(r->Lchild);
		if(r->Lchild == NULL && r->Rchild == NULL)
			printf("%c",r->data);
		InOrder(r->Rchild);
	} 
}

int leafNumber0(BiTree r){		//统计叶子节点的个数
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
int leafNumber1(BiTree r){		//采用全局变量计算二叉树中，度为1的结点的个数 
	if(r == NULL)
		return 0;
	if(((r->Lchild == NULL) && (r->Rchild != NULL)) || 
				((r->Lchild != NULL) && (r->Rchild == NULL)))
		n1++;
	leafNumber1(r->Lchild);
	leafNumber1(r->Rchild);
} 
int leafNumber2(BiTree r){		//采用全局变量计算二叉树中，度为2的结点的个数
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
/*	PreOder(r);						递归先序打印二叉树 
	printf("\n");		
	InOder(r);						递归中序打印二叉树 
	printf("\n");
	PostOder(r);					递归后序打印二叉树 		*/
	 
/*	n0 = leafNumber0(r);			输出叶子节点的个数 
	leafNumber1(r);					输出度为1的节点的个数 
	leafNumber2(r);					输出度为2的节点的个数	
	printf("%d %d %d\n",n0,n1,n2);
	InOrder(r);						输出叶子节点*/ 
	
	PreOder1(r);
	printf("\n");
	InOder1(r);
}
