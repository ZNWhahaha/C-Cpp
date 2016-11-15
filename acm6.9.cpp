#include<stdio.h>
main()
{	int i,n,m;
	float x,y;
	scanf("%d%d",&m,&n);
	x=m;
	y=m;
	for (i=1;i<=n;i++)
	{	x=x/2.0;
		if(x==n)
			y+=x;
		else if(i<n)
			y+=x*2;
	}
	printf("%.2f %.2f",x,y);
}
/*一球从M米高度自由下落，每次落地后返回原高度的一半，再落下。它在第N次落地时反弹多高？共经过多少米？保留两位小数*/
