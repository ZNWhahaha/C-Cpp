#include<stdio.h>
main()
{	int i,j,a,b;
	a=1;
	b=0;
	for(i=1;i<=20;i++)
	{	for(j=1;j<=i;j++)
			a+=j;
		b+=a;
	}
	printf("%d\n",b);
}
