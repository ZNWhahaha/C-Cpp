#include<stdio.h>
#include<math.h>
main()
{	int a[6][6],i,j,max,b,t;
	for(i=0;i<6;i++)
	{	for(j=0;j<6;j++)
			scanf("%d",&a[i][j]);
	}
	for(i=0;i<6;i++)
	{	max=abs(a[0][i]);
		for(j=0;j<6;j++)
		{	if(max<abs(a[j][i]))
			{	max=a[j][i];
				b=j;
			}
		}
		t=a[i][i];
		a[i][i]=max;
		a[b][i]=t;
	}
	for(i=0;i<6;i++)
	{	for(j=0;j<6;j++)
		{	printf("%3d",a[i][j]);
		if(j==5)
			printf("\n");} 
	}
}
