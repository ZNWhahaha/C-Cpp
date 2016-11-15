#include<stdio.h>
#include<string.h>
main()
{	char a[100][20],t[20];
	int i,j,n,k;
	printf("请输入要输入字符串的个数");
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%s",&a[i]);
	for(i=0;i<n-1;i++)
	{	k=i;
		for(j=i+1;j<n;j++)
		{	if(strcmp(a[i],a[j])>0)
				k=j;
		}
		if (k!=i)
		{	strcpy(t,a[i]);
			strcpy(a[i],a[j]);
			strcpy(a[j],t);
		}
	}
	for(i=0;i<n;i++)
		printf("%s",a[i]);
}
