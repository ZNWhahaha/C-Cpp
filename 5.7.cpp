#include<stdio.h>
main()
{	int n,i,j,k;
	scanf("%d",&n);
	for (i=n;i>0;i--)
	{	for (j=n;j>i;j--)
			printf(" ");
		for (k=1;k<=i;k++)
			printf("*");
		printf("\n");
	}
	printf("\n");
} 
