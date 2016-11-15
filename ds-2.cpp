#include<stdio.h>
int main()
{	int a,b,c,x,y,i;
	scanf("%d%d%d",&a,&b,&c);
	for(i=a;;i++)
	{	if(i%a==0&&i%b==0&i%c==0)
		{	y=i;
			break;
		}
	}
	printf("%d",y);
}
