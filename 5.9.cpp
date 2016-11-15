#include<stdio.h>
main()
{	int i,n,a;
	float s;
	for(i=1;;i++)
	{	scanf("%d",&n);
		s+=n;
		if (n<=60)
			printf("%3d",n);
		if (n<0)
		{	a=i;
			break;
		}
	}
	s=s/(1.0*a);
	printf("The sum is :%3d.\n",s);
}
