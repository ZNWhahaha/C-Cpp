#include<stdio.h>
int main()
{
	int n,i,j,k,a[50],t=0,h;
	scanf("%d",&n);
	for(i=1;i<10;i++)
		for(j=0;j<10;j++)
			for(k=0;k<10;k++)
				if((i+j)*2+k==n)
				{	a[t]=i*10001+j*1010+k*100;
					t++;
				}
				else if((i+j+k)*2==n)
				{	a[t]=i*100001+j*10010+k*1100;
					t++;
				}
	for(i=0;i<t-1;i++)
		for(j=0;j<t-1-i;j++)
		{	h=a[i];
			a[i]=a[j];
			a[j]=h;
		}
	if(t>10)
		printf("%d",t);
	if(t<=10)
		for(i=0;i<t;i++)
		{	printf("%d",a[i]);
			if(i!=(t-1))
				printf("\n");
		}
	return 0;
}

