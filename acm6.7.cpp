#include<stdio.h>
main()
{	int a[50],i,j,k,n,sum;
	scanf("%d",&n);
	for(i=2;i<=n;i++)
	{	k=0;
		sum=0;
		for(j=1;j<i;j++)
		{	if(i%j==0)
			{	a[k]=j;
				k++;
			}
		}
		for(j=0;j<k;j++)
			sum+=a[j];
		if(i==sum)
		{	printf("%d its factors are ",i);
			for(j=0;j<k;j++)
			{	if(j<k-1)
					printf("%d ",a[j]);
				else if(j==k-1)
					printf("%d \n",a[j]);
			}
		}
	}
}
/*一个数如果恰好等于它的因子之和，这个数就称为"完数"。 例如，6的因子为1、2、3，而6=1+2+3，因此6是"完数"。 编程序找出N之内的所有完数，并按下面格式输出其因子：*/
