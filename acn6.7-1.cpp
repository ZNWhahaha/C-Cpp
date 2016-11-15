#include<stdio.h>
int main(void)
{	int a,b,i,j,k,n;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{	a=0;
		for(j=1;j<i;j++)
		{	if(i%j==0)
				a=a+j;
		}
		if(a==i)
		{ 	printf("%d its factors are ",i);
			for(j=1;j<i;j++)
			{	b=0;
				if(i%j==0)
				{	b=b+j;
					printf("%d ",j);
				}
			}
			printf("\n"); 
		}
	}
}
