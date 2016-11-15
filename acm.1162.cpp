/*前100个自然数之和为S=1+2+3+...+100。要求编写和调用递归函数实现该计算。*/
#include<stdio.h>
int digui(int n)
{	int a;
	if(n==1)	return 1;
	a=n+digui(n-1);
	return a;	
} 
main()
{	int n=100;
	printf("%d",digui(n));
}
