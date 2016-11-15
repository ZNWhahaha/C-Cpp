#include<stdio.h>
main()
{	int i,j,a,k=0,flag;
	for(i=50;i<=200;i++)
	{	a=0;flag=0;
		for(j=2;j<i;j++)
		{	if(i%j!=0)
				break;
			flag=1;
			a=i;
		}
		if(a>0&&flag==1)			
		{	printf("%5d",a);
			k+=1;
			if(k%5==0)
				printf("\n");
		}
	}		
}
