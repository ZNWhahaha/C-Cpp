#include<stdio.h>
int num(int x,int y)
{	int i,sum=0;
	for(i=x;i<=y;i++)
		sum+=i;
	return sum;
}
int main()
{	int n,i,j,k,h=0,flag=1;
	scanf("%d",&n);
	for(i=1;i<n;i++)
	{	for(j=n;j>i;j--)
		{	if(n==num(i,j))
				h++;
		}
	}
	for(i=1;i<n;i++)
	{	for(j=n;j>i;j--)
		{	if(n==num(i,j))
			{	printf("%d=%d",n,i);
				for(k=i+1;k<=j;k++)
					printf("+%d",k);
				h--;
				if(h!=0)
				printf("\n");
				flag=0;
			}	
		}
	}
	if(flag==1)
		printf("NONE");
}
