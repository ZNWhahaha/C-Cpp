#include<stdio.h>
main()
{	int x,y,i,j,t,a[100],b[100];
	scanf("%d,%d",&x,&y);
	for(i=0;i<x;i++)
		scanf("%d",&a[i]);
	for(i=0;i<y;i++)
		scanf("%d",&b[i]);
	for(i=0;i<y;i++)
		a[x+i]=b[i];
	for(i=0;i<(x+y);i++)
	{	for(j=0;j<(x+y);j++)
		{	if(a[i]<a[j])
			{	t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}
	}
	for(i=0;i<(x+y);i++)
		printf("%d ",a[i]);
}
