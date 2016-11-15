#include<stdio.h>
#define PI 3.14
main()
{	float r,h,a,b,c,d,e;
	scanf("%f%f",&r,&h);
	a=2*PI*r;
	b=PI*r*r;
	c=4*PI*r*r;
	d=(4/3.0)*PI*r*r*r;
	e=b*h;
	printf("C1=%.2f\n",a);
	printf("Sa=%.2f\n",b);
	printf("Sb=%.2f\n",c);
	printf("Va=%.2f\n",d);
	printf("Vb=%.2f",e);
}
