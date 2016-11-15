#include<stdio.h>
int shuixianhua(int n)
{	int a,b,c;
	a=n/100;
	b=n%100/10;
	c=n%10;
	if(a*a*a+b*b*b+c*c*c==n)
		printf("%5d",n);
}
main()
{	int i;
	printf("100~999的水仙花数为：\n");
	for(i=100;i<1000;i++)
		shuixianhua(i);
}
