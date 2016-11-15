#include<stdio.h>
long f(int n)
	{	
		if (n==1)
			return 1;
		return n+f(n-1);
	}
main()
{	int i;
	double a=1.0;
	for (i=1;;i++)
	{	a+=(1.0/f(i));
		if (1/f(i)<0.0000001)
			break;
	}
	printf("e=%lf",a);
}


