#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
main()
{	int i,j,*a=NULL,num,flag;
	scanf("%d",&num);
	a=(int *)malloc(sizeof(int)*num);
	for (i=0;i<num;i++)
		a[i]=i+1;
	for(i=1;i<num;i++)
	{	flag=1;
		for(j=2;j<num;j++)
		{	if(a[i]%j==0)
			{	flag=0;
				break;
			}
			if(flag==1)
				printf("%d\n",a[i]);
				break;
		}
	}
	free(a);
}
/*用筛法求之N内的素数。*/ 
