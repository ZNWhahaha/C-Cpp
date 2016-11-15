#include <stdio.h>
#include <math.h>
long int fun(int x,int n)
{
	int i;
	long int s=0,f;
	i=1;
	while(i<=n)
	{
		if(i==0)
			return 1;
		else
			f=fun(x,i-1)*x;
		s=s+(pow(-1,i)*f); 
		i++;
	}
	printf("%ld",s);
}
main()
{
	int x,n;
	scanf("%d %d",&x,&n);
	fun(x,n);
}
