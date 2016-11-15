#include<stdio.h>
main()
{	int a,b,c,m;
	scanf("%d%d%D",&a,&b,&c);	
	if (a>b)
		m=a;
	else
		m=b;
	if (m<c)
		m=c;
	printf("%d",m);
}
