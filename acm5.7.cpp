#include<stdio.h>
main()
{	int x,a,b,c,d,e,y;
	scanf("%d",&x);
	if(x/10000!=0)
	{	printf("5\n");
		a=x/10000;
		b=x%10000/1000;
		e=x%1000/100;
		c=x%100/10;
		d=x%10;
		y=d*10000+c*1000+e*100+b*10+a;
		printf("%d %d %d %d %d\n",a,b,e,c,d);
		printf("%d\n",y);
	}
	else if (x/1000!=0)
	{	printf("4\n");
		a=x/1000;
		b=x%1000/100;
		c=x%100/10;
		d=x%10;
		y=d*1000+c*100+b*10+a;
		printf("%d %d %d %d\n",a,b,c,d);
		printf("%d\n",y);
	} 
	else if (x/100!=0)
	{	printf("3\n");
		a=x/100;
		b=x%100/10;
		c=x%10;
		y=c*100+b*10+a;
		printf("%d %d %d\n",a,b,c);
		printf("%d\n",y);
	}
	else if (x/10!=0)
	{	printf("2\n");
		a=x/10;
		b=x%10;
		y=b*10+a;
		printf("%d %d\n",a,b);
		printf("%d\n",y);
	}
	else if (x/10==0)
	{	printf("1\n");
		a=x;
		y=x;
		printf("%d\n",a);
		printf("%d\n",y);
	}
}
