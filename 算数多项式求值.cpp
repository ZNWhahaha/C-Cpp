#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OPSETSIZE  7

typedef int Elemtype;

typedef struct Stacknode{
	Elemtype data;
	struct Stacknode *next;
}slStacktype; 

int Push(slStacktype *top, Elemtype x){
	slStacktype *p;
	if( (p = (slStacktype *)malloc(sizeof(slStacktype))) == NULL)
		return FALSE;
	p->data = x;
	p->next = top->next;
	top->next = p;
	return TRUE;
}

Elemtype Putout(slStacktype *top){
	slStacktype *p;
	Elemtype x;
	if(top->next = NULL)
		return NULL;
	p = top->next;
	top->next = p->next;
	*x = p->data;
	free(p);
	return x;
}

char OPSET[OPSETSIZE]={'+','-','*','/','(',')','#'};
unsigned int Prior[7][7] = {     //符号优先级关系矩阵 
	'1',1','-1','-1','-1','1','1',
	'1','1','-1','-1','-1','1','1',
	'1','1','1','1','-1','1','1',
	'1','1','1','1','-1','1','1', 
	'-1','-1','-1','-1','-1','0','0',
	'1','1','1','1','0','1','1',
	'-1','-1','-1','-1','-1','0','0'
};  

int Compare(char a,char b){		//字符优先级比肩
	if((a == '(') &&  (b == '+' || b =='-' || b == '/' || b == '*')
		return 1;
	if((a == '+' || a =='-')  && (b == '*' || b == '/'))
		return 0; 
} 

