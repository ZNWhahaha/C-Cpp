#include <stdio.h>
int main()
{
	int i,j,m,n,x,y;
	while(scanf("%d, %d",&m,&n)!=EOF)
	{
		int a[m][n],b[m][n];
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
				scanf("%d",&a[i][j]);
		}
		x=0;
		y=0;
		for(j=1;j<n;j++)
		{
				for(i=0;i<m;i++)
				{
					b[x][y]=a[i][j];
					x++;
				}
				x=0;
				y++;
		}
		
		for(x=0;x<m;x++)
		{
			b[x][n-1]=a[i][0];
			i++;
		}
		for(x=0;x<m;x++)
		{
			for(y=0;y<n;y++)
			printf("%d ",b[x][y]);
			printf("\n");
		}
	}
}

