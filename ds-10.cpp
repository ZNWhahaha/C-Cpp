/*#include<stdio.h>
int main()
{	int n,i,a,b,c,d,e,f,num=0,z[10];
	scanf("&d",&n);
	for(i=10000;i<100000;i++)
	{	a=i/10000;
		b=i%10000/1000;
		c=i%1000/100;
		d=i%100/10;
		e=i%10;
		if( (a+b+c+d+e)==n && a==e && b==d)
		{	z[num]=i;
			num++;	
		}
	}
	for(i=100000;i<1000000;i++)
	{	a=i/100000;
		b=i%100000/10000;
		c=i%10000/1000;
		d=i%1000/100;
		e=i%100/10;
		f=i%10;
		if( (a+b+c+d+e+f)==n && a==f && b==e && c==d)
		{	z[num]=i;
			num++;
		}	
	}
	if(num<10)
	{	for(i=0;i<num;i++)
			printf("%d\n",z[i]);
	}
	else
		printf("%d",num);
}
#include<stdio.h>
int main()
{	int n,i,sum=0,num=0;
	scanf("%d",&n);
	int a[6],b[100];
	for(i=0;i<5;i++)
		scanf("%d",&a[i]);
	for(i=0;i<5;i++)
		sum+=a[i]
	if(a[0]==a[4]&&a[1]==[3]&&sum==n)
	{	b
		num++;
	for(i=0;i<6;i++)
		sum+=a[i]
	if(a[0]==a[5]&&a[1]==[4]&&a[2]==a[3]&&sum==n)
		num++;
	if(num>10)
		printf("%d",num);
	else
	{
	}	
}*/
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n,temp,i,t=0,x;
    int sum=0,a[100];
    scanf("%d", &n);
	for(i=10000;i<10000000;i++)
	{	temp=i;
		while(i)
   		{
        	sum = sum*10 + i%10; 
        	i /= 10;
    	}
    	if(temp==sum) 
    	{	a[t]=temp;
    		t++;
		}
	}
	if(t>10)
		printf("%d",t);
	else
		for(i=0;i<t;i++)
		{	x=atoi(a[i]);
			printf("%d",x);
			if(i!=(t-1))
				printf("\n");
		}
    return 0;
}

