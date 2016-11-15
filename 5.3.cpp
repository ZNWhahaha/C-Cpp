#include<stdio.h>
main()
{	int i, j, n,s;
	scanf("%d",&n);
	s=0;
	for (i=1;i<=n;i++)
	{	for (j=1;j<=i;j++)
			s+=j;	
	}
	printf("The sum  is : %d.\n",s);
}
