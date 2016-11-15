#include<stdio.h>
#include<string.h>
void hanshu(char a[])
{	int i,e=0,b=0,c=0,d=0;
	for(i=0;i<strlen(a);i++)
	{	if(a[i]==' ')
			e++;
		else if(a[i]>=48&&a[i]<=57)
			b++;
		else if(a[i]>=65&&a[i]<=90)
			c++;
		else if(a[i]>=97&&a[i]<=122)
			c++;
		else
			d++;
	}
	printf("%d %d %d %d",c,b,e,d);
}
main()
{	char a[50];
	gets(a);
	hanshu(a);	
} 
