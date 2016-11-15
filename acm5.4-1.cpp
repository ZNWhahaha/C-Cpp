#include<stdio.h>
int max(int a,int b)
{	if (a>b)
		return a;
	else
		return b;
}
main()
{	int a,b,c,d;
	scanf("%d%d%d",&a,&b,&c);
	d=max(a,b);
	d=max(d,c);
	printf("%d",d);
}
