#include<stdio.h>
main()
{	int x,y,i,j,t,a[100][100];
	while(scanf("%d,%d",&x,&y)!=EOF)
	{	for(i=0;i<x;i++)
		{	for(j=0;j<y;j++)
				scanf("%d",&a[i][j]);
		}
		for(j=0;j<y;j++)
		{	for(i=0;i<x;i++)
			{	t=a[i+1][j];
				a[i+1][j]=a[i][j];
				a[i][j]=t;
			}
		}
		for(i=0;i<x;i++)
		{
			for(j=0;j<y;j++)
			printf("%5d",a[i][j]);
			printf("\n");
		}
	}
}
