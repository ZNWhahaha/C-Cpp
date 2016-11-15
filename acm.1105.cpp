#include<stdio.h>
#include<math.h>
long int sum=0;
long int hanshu(int x, int n)
{	long int f;
	if(n==0)	return sum;
	f=(-1)*(n-1)*pow(x,n)*hanshu(x,n-1);
	return f;
} 
main()
{	int x,y;
	scanf("%d,%d",&x,&y);
	printf("%ld",hanshu(x,y));
}
