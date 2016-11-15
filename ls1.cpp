#include<stdio.h>
main()
{	int m,i,flag,n;
	scanf("%d",&n);
	for (m=2;m<=n;m++)
	{	flag=1;
		for(i=2;i<m;i++)
		{	if (m%i==0)
			{	flag=0;
				break;
			}
		}
		if(flag==1)
			printf("%d\n",m);
	}
 } 
