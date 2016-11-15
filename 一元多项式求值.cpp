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
int Num_polyn(int x,Polyn *a){
	Polyn *h;
	int sum = 0;
	for(h = a->next;h;h = h->next){
		sum += h->coef * pow(x,h->expn);
	}
	return sum;
}
int main(){
	Polyn *H1;
	int n1,n2,sum;
	scanf("%d\n",&n1);
	H1 = Creat_polyn(n1);
	scanf("%d",&n2);
	sum = Num_polyn(n2,H1);
	printf("%d",sum);
	return 1;
}
