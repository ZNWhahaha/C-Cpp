#include<stdio.h>
#include<string.h>
main()
{
    char a1[100],a2[100];
    gets(a1);
    int j = 0;
    for(int i = 0;i<strlen(a1);i++)
       if(a1[i]=='a'||a1[i]=='e'||a1[i]=='i'||a1[i]=='u'||a1[i]=='o')
         {
            a2[j] = a1[i];
            j++;
         }
    printf("%s",a2);       
}
