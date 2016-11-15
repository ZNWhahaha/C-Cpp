#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int sushu(int x)
{	int i,flag=1;
	for(i=2;i<x;i++)
		if(x%i==0)
		{	flag=0;
			break;
		}
	if(flag==1)
		return 1;
	else
		return 0;
}
int main()
{	int n,i,j,a,b,c,d;
	scanf("%d",&n);
	char A[n][100],B[100];
	for(i=0;i<n;i++)
		scanf("%s",&A[i]);
	for(i=0;i<n;i++)
	{	a=strlen(A[i]);
		b=a-1;
		c=atoi(A[i]);
		for(j=0;j<a;j++)
		{	B[j]=A[i][b];
			b--;
		}
		d=atoi(B);
		if(sushu(c)==1)
		{	if(sushu(d)==1)
				printf("%d是可逆素数",c);
			if(sushu(d)==0)
				printf("%d是素数，但不是可逆素数",c);
		}
		else
			printf("%d不是素数",c);
		if(i!=(n-1))
			printf("\n");
	}
}
