/*дһ���ж������ĺ�����������������һ������������Ƿ�����������Ϣ*/
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
