#include<stdio.h>
#include<stdlib.h>


//typedef struct{};
 
typedef struct Node{
	char data; 
	struct Node *Lchild;
	struct Node *Rchild;
}BiTNode,*BiTree;	

//������չ�����������������������

void Creat(){
	BiTree r;
	char ch;
	ch = getchar();
	if(ch == '#')
		r = NULL;
	else{
		r =(BiTree )malloc(sizeof(BiTNode));
		r->data = ch;
		r->Lchild = Creat();
		r->Rchild = Creat();
	}
} 

void InOrder1(BiTree root){

}
void PreOder(BiTree root){
	if(root){
		printf("%s",root->data);
		PreOder(root->Lchild);
		PreOder(root->Rchild);
	}
}
