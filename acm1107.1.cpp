#include<stdio.h>
#include<string.h>
void hanshu(char a[])
{	char b[50];
	int j=0,i;
	 for(i=0;i<strlen(a);i++)
       if(a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='u'||a[i]=='o')
         {
            b[j] = a[i];
            j++;
         }
    printf("%s",b);  
}
main()
{	char a[50];
	scanf("%s",a);
	hanshu(a);
}
