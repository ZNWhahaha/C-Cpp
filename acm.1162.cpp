/*ǰ100����Ȼ��֮��ΪS=1+2+3+...+100��Ҫ���д�͵��õݹ麯��ʵ�ָü��㡣*/
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
