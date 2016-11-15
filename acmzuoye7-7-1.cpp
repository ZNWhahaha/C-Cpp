#include <stdio.h>
int main()
{
	int i,j,c,d,x,y;
	while(scanf("%d,%d",&c,&d)!=EOF)
	{
		int a[c][d],b[c][d];
		for(i=0;i<c;i++)
		{
			for(j=0;j<d;j++)
				scanf("%d",&a[i][j]);
		}
		x=0;
		y=0;
		for(j=1;j<d;j++)
		{
				for(i=0;i<c;i++)
				{
					b[x][y]=a[i][j];
					x++;
				}
				x=0;
				y++;
		}
		i=0;
		for(x=0;x<c;x++)
		{
			b[x][d-1]=a[i][0];
			i++;
		}
		for(x=0;x<c;x++)
		{
			for(y=0;y<d;y++)
			printf("%5d",b[x][y]);
			printf("\n");
		}
	}
}
