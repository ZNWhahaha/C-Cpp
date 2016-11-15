#include<stdio.h>
main()
{	int i,j,a,k=0,flag=1;
	for(i=50;i<=200;i++)
	{
	flag=1;	a=0;
		for(j=2;j<i;j++)
		{		
			if(i%j==0)
			{
		
			flag=0;
				break;}
		
			a=i;
		}
		if(flag==1&&a>0)
		{	printf("%5d",a);
			k+=1;
			if(k%5==0)
				printf("\n");
		}
	}
}
