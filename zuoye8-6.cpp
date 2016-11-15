#include<stdio.h>
#include<math.h>
int sushu(int n)
{
	int i;
	for(i=2; i<=sqrt(n); i++)
	{
		if(n%i == 0)
		{
			return 0;
		}
		if(i>sqrt(n))
		{
			return 1;
		}
	}
}
int sushuyinzi(int m)
{	int i;
	for(i=2;i<=sqrt(m); i++)
	{
		if(m%i == 0)
		{
			if(sushu(i))
			{
				printf("%d ",i);
				m /= i;
				i = 1;
			}
		
		}
	
	}
	if(i>sqrt(m))
	{
		printf("%d ",m);
	}
}
main()
{
	int m;
	printf("ÊäÈëÕûÊım:");
	scanf("%d",&m);
	sushuyinzi(m);
}
