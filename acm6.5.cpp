#include<stdio.h>
#include<math.h>
main()
{	double a,b,c,x=0,y=0,z=0,i;
	scanf("%lf%lf%lf",&a,&b,&c);
	for(i=1;i<=a;i++)
		x+=i;
	for(i=1;i<=b;i++)
		y+=i*i;
	for(i=1;i<=c;i++)
		z+=1.0/i;
	i=x+y+z;
	printf("%.2lf",i);
} 
