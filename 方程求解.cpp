#include<stdio.h>
#include<math.h>
#include<stdlib.h>
void dayu(float a,float b,float c)
{	printf("x1=%.3f x2=%.3f",((-b+sqrt(b*b-4*a*c))/(2*a)),((-b-sqrt(b*b-4*a*c))/(2*a)));
}
void dengyu(float a,float b,float c)
{	printf("x1=%.3f x2=%.3f",(-b/(2*a)),(-b/(2*a)));
}
void xiaoyu(float a,float b,float c)
{	printf("x1=%.3f+%.3fi ",(-b/(2*a)), sqrt(fabs(b*b-4*a*c))/(2*a));
	printf("x2=%.3f-%.3fi",(-b/(2*a)), sqrt(fabs(b*b-4*a*c))/(2*a));
}
main()
{	float a,b,c,t;
	scanf("%f %f %f",&a,&b,&c);
	t=b*b-4*a*c;
	if(t>0)
		dayu(a,b,c);
	else if(t==0)
		dengyu(a,b,c);
	else
		xiaoyu(a,b,c); 
}
