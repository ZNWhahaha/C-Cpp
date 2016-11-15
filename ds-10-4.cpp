#include<stdio.h>
int main()
{
 int a,b,c,d,e,f,n,t=0;
 long i,num[100];
 scanf("%d",&n);
 for(i=10000;i<=99999;i++)
 {  
   b=i/10000;
   c=i/1000%10;
   d=i/100%10;
   e=i/10%10;
   f=i%10;
    if((b==f&&c==e)&&b+c+d+e+f==n)
    {	num[t]=i;
			t++;
	}
 }
  for(i=100000;i<=999999;i++)
 {  
   a=i/100000;
   b=i/10000%10;
   c=i/1000%10;
   d=i/100%10;
   e=i/10%10;
   f=i%10;
   if((a==f&&b==e&&c==d)&&a+b+c+d+e+f==n)
   {	num[t]=i;
			t++;
   }
}
if(t>10)
		printf("%d",t);
	if(t<=10)
		for(i=0;i<t;i++)
		{	printf("%d",num[i]);
			if(i!=(t-1))
				printf("\n");
		}
return 0;
}
