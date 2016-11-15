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
		if(p->coef != 0 && p->expn != 0 && p->expn != 1){
			printf("%.dX^%d",p->coef,p->expn);		
		}
		else if(p->coef != 0 && p->expn == 0){
			printf("%.d",p->coef);
		}
		else if(p->coef != 0 && p->expn == 1){
			printf("%dX",p->coef);
		}
		p=p->next;
		if(p == NULL)
			break;
		if(p->coef > 0){
			printf("+");
		}
	}
}

Polyn *Chen_Polyn(Polyn *a,Polyn *b){
	Polyn *h1,*h2,*h3,*h;
	h = h3;
	for(h1 = a->next;h1;h1 = h1->next){
		for(h2 = b->next;h2;h2 = h2->next){
			h3->coef = h1->coef * h2->coef;
			h3->expn = h1->expn + h2->expn;
			h3 = h3->next;
		}
	}
	h3->next = NULL;
	return h;
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
	Polyn *H1,*H2,*H;
	int n1,n2,sum;
	scanf("%d\n",&n1);
	H1 = Creat_polyn(n1);
	Print_polyn(H1);
	scanf("%d\n",&n2);
	H2 = Creat_polyn(n2);
	Print_polyn(H2);
	H = Chen_Polyn(H1,H2);
	paixu(H);
	Print_polyn(H);
	return 1;
}




























