#include<stdio.h>
main()
{	int i,j,k=1 ;
	for (i=50;i<=200;i++)
	{	for(j=2;j<i;j++)
		{	if(i%j==0)
				break;
			else
			{	printf("%3d",j);
				k+=1;
				if(k%5==0)
					printf("\n");
			}
		}
	} 
}
