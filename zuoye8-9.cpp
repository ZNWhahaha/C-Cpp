/*�����ݼ����ĵݹ麯��*/
#include<stdio.h>
int mijishu(int x,int n)
{	int a;
	if(n==0)	return 1;
	a=x*mijishu(x,n-1);
	return a;
}
int main(void)
{	int x,n;
	scanf("%d %d",&x,&n);
	printf("����ֵΪ:%d",mijishu(x,n));
}
