#include <stdio.h>
main()
{
	int i,j,k,b,c;
	int a[3][3];
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
			scanf("%d",&a[i][j]);
	}
	for(k=0;k<3;k++)
	{
		for(i=0;i<3;i++)
		{
			for(j=0;j<2;j++)
			{
				if(a[i][j]>a[i][j+1])
				{
					b=a[i][j];
					a[i][j]=a[i][j+1];
					a[i][j+1]=b;
				}
			}
		}
		for(j=0;j<3;j++)
		{
			for(i=0;i<2;i++)
			{
				if(a[i][j]>a[i][j+1])
				{
					c=a[i][j];
					a[i][j]=a[i][j+1];
					a[i][j+1]=c;
				}
			}
		}
	}
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
			printf("%d ",a[i][j]);
		printf("\n");
	}
}
