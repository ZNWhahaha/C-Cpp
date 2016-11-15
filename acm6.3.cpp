#include<stdio.h>
#include<math.h>
int main(void)
{	int i,n,a=0,b=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{	a=a+2*pow(10,i);
		b+=a;
		printf("%d\t%d\n",b,a);
	}
	printf("%d",b);
	return 0;
} 
