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
/*һ���M�׸߶��������䣬ÿ����غ󷵻�ԭ�߶ȵ�һ�룬�����¡����ڵ�N�����ʱ������ߣ������������ף�������λС��*/
