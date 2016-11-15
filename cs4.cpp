#include<stdio.h>
main()
{	int i,j,k,n;
	scanf("%d",&n);
	for (i=1;i<=n/2+1;i++)
	{	for(j=2;j>=i;j--)
			printf(" ");
		for(k=1;k<=2*i-1;k++)
			printf("*");
		printf("\n");
	}
	for(i=n/2;i>0;i--)
	{	for(j=1;j<i;j++)
			printf(" ");
		for(k=1;k<=2*(n/2-1)-1;k++)
			printf("*");
		printf("\n");
	}	
	
}
