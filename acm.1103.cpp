/*写一个判断素数的函数，在主函数输入一个整数，输出是否是素数的消息*/
#include<stdio.h>
void sushu(int n)
{	int i,flag=1;
	for(i=2;i<n;i++)
	{	if(n%i==0)
		{	flag=0;
			break;
		}
	}
	if(flag==1)
		printf("prime");
	else
		printf("not prime");
}
main()
{	int n;
	scanf("%d",&n);
	sushu(n);
} 
