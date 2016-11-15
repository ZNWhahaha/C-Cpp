#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
int f(int num)
{	int i,j,flag;
	for (i=1;i<num;i++)
	{	flag=1;
		for(j=i+1;j<num;j++)
		{	if (a[j]%a[i]==0)
			{	flag=0;
				break;
			}
		}
		if(flag==1)
			return a[i];
		else
			return 0;
	}
 } 
main()
{	int i,j,*a=NULL,num,flag;
	scanf("%d",&num);
	a=(int *)malloc(sizeof(int)*num);
	for (i=0;i<num;i++)
		a[i]=i+1;
	printf("%d\n",f(num));
}
