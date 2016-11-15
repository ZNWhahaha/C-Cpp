#include<stdio.h>
int f(int n)
{	if(n==1)
		return 1;
	return n*f(n-1);
}
main()
{	int i,s=0;
	for(i=1;i<=5;i++)
		s+=f(i);
	printf("%d",s);
}

