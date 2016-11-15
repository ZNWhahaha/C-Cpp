#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct polyn
{
	int coef;
	int expn;
	struct polyn *next;
}Polyn;

Polyn *Creat_polyn(int n){
	int c;
	int e;
	char t1,t2,t3;
	Polyn *head,*rear,*s;
	head = (Polyn *)malloc(sizeof(Polyn));
	rear = head;
	while(n){
		scanf("%c%d%c%d%c",&t1,&c,&t2,&e,&t3);
		s=(Polyn *)malloc(sizeof(Polyn));
		s->coef = c;
		s->expn = e;
		rear->next = s;
		rear = s;
		n--;
	}
	rear->next = NULL;
	return head;
}

int Print_polyn(Polyn *H){
	Polyn *p;
	p = H->next;
	if(p == NULL){
		return 0;
	}
	while(p != NULL){
		if(p->coef != 0 && p->expn-1 != 0 && p->expn-1 != 1 && p->expn-1 >0){
			printf("%.dX^%d",p->coef*p->expn,p->expn-1);		
		}
		else if(p->coef != 0 && p->expn-1 == 0){
			printf("%.d",p->coef);
		}
		else if(p->coef != 0 && p->expn-1 == 1){
			printf("%dX",p->coef);
		}
		p=p->next;
		if(p == NULL)
			break;
		if(p->coef > 0 && p->expn-1 >0){
			printf("+");
		}
	}
}
void paixu(Polyn *H){
	Polyn *p1,*p2,*t;
	p1 = H;
	p2 = H;
	for(p1; p1!=NULL; p1=p1->next){
		for(p2; p2!=NULL; p2=p2->next){
			if(p1->expn > p2->expn){
				t=p1;
				p1->next = p2->next;
				p1=p2;
				p2->next = t->next;
				p2 = t;
			}
		}
	}
}

int main(){
	Polyn *H1;
	int n1,n2,sum;
	scanf("%d\n",&n1);
	H1 = Creat_polyn(n1);;
	paixu(H1);
	Print_polyn(H1);
	return 1;
}
