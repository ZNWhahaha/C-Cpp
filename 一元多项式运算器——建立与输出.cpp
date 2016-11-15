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

Polyn *Add_polyn(Polyn *a,Polyn *b){
	Polyn *qa,*qb,*qc,*pc,*head;
	qa = a->next;
	qb = b->next;
	pc = (Polyn *)malloc(sizeof(Polyn));
	pc->next = NULL;
	head = pc;
	while(qa != NULL && qb != NULL){
		qc = (Polyn *)malloc(sizeof(Polyn));
		if(qa->expn < qb->expn){
			qc->coef = qa->coef;
			qc->expn = qa->expn;
			qa = qa->next;
		}
		else if(qa->expn == qb->expn){
			qc->coef = qa->coef + qb->coef;
			qc->expn = qa->expn;
			qa = qa->next;
			qb = qb->next;
		}
		else{
			
			qc->coef = qb->coef;
			qc->expn = qb->expn;
			qb = qb->next;
		}
		if(qc->coef != 0){
			qc->next = pc->next;
			pc->next = qc;
			pc = qc;
		}
		else 
			free(qc);
	}
	while(qa != NULL){
		qc = (Polyn *)malloc(sizeof(Polyn));
		qc->coef = qa->coef;
		qc->expn = qa->expn;
		qa = qa->next;
		qc->next = qc->next;
		pc->next = qc;
		pc = qc;
	}
	while(qb != NULL){
		qc = (Polyn *)malloc(sizeof(Polyn));
		qc->coef = qb->coef;
		qc->expn = qb->expn;
		qb = qb->next;
		qc->next = qc->next;
		pc->next = qc;
		pc = qc;
	}
	return head;
}

int Num_polyn(int x,polyn *a){
	polyn *h;
	int sum = 0;
	for(h = a->next;h;h = h->next){
		sum += h->coef * pow(x,h->expn);
	}
	return sum;
}

Polyn *Sub_polyn(Polyn *a,Polyn *b){
	Polyn *h,*p,*d,*d1;
	h = b;
	p = b->next;
	while(p){
		p->coef *= -1;
		p = p->next;
	}
	d = Add_polyn(a,h);
	for(d1 = d->next;d1;d1 = d1->next )
		if(d1->coef == 0)
			free(d1); 
	for(p = h->next;p;p = p->next)
		p->coef *= -1;
	return d;
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
	scanf("%d",&n2);
	sum = Num_polyn(n2,H1);
	printf("%d",sum);
//	scanf("%d\n",&n2);
//	H2 = Creat_polyn(n2);
//	H = Sub_polyn(H1,H2);
//	paixu(H);
//	Print_polyn(H);
	return 1;
}
