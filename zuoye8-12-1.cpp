#include<stdio.h>
main()
{	int i,a[10],n;
	a[0]=2;
	a[1]=3;
	for(i=2;i<10;i++)
	{	n=a[i-1]*a[i-2];
		if(n<10)
			a[i]=n;
		else
		{	a[i]=n/10;
			a[++i]=n%10;
		}
	}
	for(i=0;i<10;i++)
		printf("%d ",a[i]);
} 
