#include <stdio.h>
#include <math.h>
main()
{
	int i,j,m,a,x,y,e,f,p,q,b;
	m=1;
	scanf("%d%d%d",&a,&x,&y);
	int arr[30/a][a];
	for(i=0;i<(30/a);i++)
	{
		if(i%2==0)
		{
			for(j=0;j<a;j++)
				{
					arr[i][j]=m;
					m++;
				}
		}
		if(i%2!=0)
		{
			for(j=a-1;j>=0;j--)
			{
				arr[i][j]=m;
				m++;
			}
		}
	}
	if(x<y)
	{
		i=x;
		x=y;
		y=i;
		
	}
	for(i=0;i<(30/a);i++)
	{
		for(j=0;j<a;j++)
		{
			if(arr[i][j]==x)
			{
				e=i;f=j;break;
			}
		}
	}
	for(i=0;i<(30/a);i++)
	{
		for(j=0;j<a;j++)
		{
			if(arr[i][j]==y)
			{
				p=i;q=j;break;
			}
		}
	}
	b=(e-p)+(f-q);
	printf("%d",b);
}
