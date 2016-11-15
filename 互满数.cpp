#include<stdio.h>
int humanshu(int a)
{	int i,sum=0;
	for(i=1;i<a;i++)
		if(a%i==0)
			sum+=i;
	return sum;
}
main()
{	int i,j,n;
	scanf("%d",&n);
	for(i=1;i<n;i++)
	{	j=humanshu(i);
		if(j>i&&humanshu(j)==i)
			printf("%d %d\n",i,j);
	}
}
