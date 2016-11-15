#include<stdio.h>
#include<stdlib.h>
int main()
{	int n,i,j,temp,x;
	int sum=0,t=0,h=0,a[50];
	scanf("%d",&n);
	for(i=10000;i<100000;i++)
	{	temp=i;
		while(i)
		{	sum=sum*10+i%10; 
        	i/=10;
        	h+=i/10;
    	}
    	if(temp==sum&&h==n) 
    	{	a[t]=temp;
    		t++;
		}
	}
	if(t>10)
		printf("%d",t);
	else
		for(i=0;i<t;i++)
		{	printf("%d",a[i]);
			if(i!=(t-1))
				printf("\n");
		}
}
