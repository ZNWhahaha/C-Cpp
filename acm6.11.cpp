#include<stdio.h>
#include<math.h>
main()
{
	float a,x0,x1;
	int flag=1;
	scanf("%f",&a);
	x0=1;
	x1=x0+1;
	while(fabs(x0-x1)>=1e-5)
	{
	x0=x1;
	x1=0.5*(x0+a/x0);
	}
	printf("%.3f",x1);
}
/*用迭代法求一个数的平方根*/ 
