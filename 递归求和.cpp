#include<stdio.h>
long f(int n)
	{	
		if (n==1)
			return 1;
		return n+f(n-1);
	}
main()
{	int n,i,s=0;
	printf("Please input n:");
	scanf("%d",&n);
	for (i=1;i<=n;i++)
		s+=f(i);
	printf("The sum is : %d",s);
}	
