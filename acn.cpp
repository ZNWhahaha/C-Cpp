#include<stdio.h>
int main(void)
{	int i=0,j,k,t,a[100];
	while(scanf("%d",&a[i])!=EOF)
	{	for(j=0;j<=i;j++)
		{
			for(k=j+1;k<=i;k++)
			{
				if(a[j]>a[k])
				{	t=a[j];
					a[j]=a[k];
					a[k]=t;
				}
			}
		}
		for(k=0;k<=i;k++)
		printf("%d ",a[k]);
		printf("\n");
		i++;
	}
}
