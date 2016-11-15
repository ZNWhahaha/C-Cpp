/*#include<stdio.h>
#include<math.h>
#define S(a,b,c) (a+b+c)*0.5
#define are(a,b,c) S(a,b,c)*(S(a,b,c)-a)*(S(a,b,c)-b)*(S(a,b,c)-c)
main()
{	float a,b,c,d;
	scanf("%f %f %f",a,b,c);
	d=sqrt(are(a,b,c));
	printf("%.3f",d);
}*/
#include<stdio.h>
#include<math.h>
main()
{	float a,b,c,d,e;
	scanf("%f%f%f",&a,&b,&c);
	d=(a+b+c)*0.5;
	e=sqrt(d*(d-a)*(d-b)*(d-c));
	printf("%.3f",e);
}
