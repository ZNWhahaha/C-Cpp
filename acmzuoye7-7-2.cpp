#include<stdio.h>
main()
{
	int x,i,j,t,m,n;
	scanf("%d,%d",&m,&n);
	int a[m][n];
	for (i=0;i<m;i++)
	{
		for (j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	}
	for (i=0;i<m;i++)
	{
		for (j=0;j<n;j++);
		{ 
			t=a[i][j];
			a[i][j]=a[i][j+1];
			a[i][j+1]=t;
		} 
		
	}
	for (i=0;i<m;i++)
	{
		for (j=0;j<n;j++)
			printf("%5d",a[i][j]);
			printf("\n");
	}
}
