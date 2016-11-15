#include<stdio.h>
#include<string.h>
main()
{	/*int i,j,a[][4]={1,2,3,4,5,6,7,8,9,10,11};
	for(i=1;i<3;i++)
		for(j=i;j<4;j++)
			a[i][j]+=a[i][j-1];
	for(i=0;i<3;i++)
		for(j=0;j<4;j++)
			printf("%5d",a[i][j]);
	char st[16]="123456\0abcdef";
	printf("%d %d %s",strlen(st),sizeof(st),st);*/
	int d[10]={1,2,3,4,5,6,7,8,9,10},*p=d+8;
	printf("%d\n",*++p-8);
}
