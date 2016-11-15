#include<stdio.h>
main()
{	int a[3][3],i,j,s1=0,s2=0;
	for(i=0;i<3;i++)
	{	for(j=0;j<3;j++)
			scanf("%d",&a[i][j]);
	}
	for(i=0;i<3;i++)
	{	for(j=0;j<3;j++)
			if(i==j)
				s1+=a[i][j];
	}
	for(i=1;i<=3;i++)
	{	for(j=1;j<=3;j++)
			if(i+j==4)
				s2+=a[i-1][j-1]; 
	}
	printf("%d %d",s1,s2);
}
/*求一个3×3矩阵对角线元素之和。*/
