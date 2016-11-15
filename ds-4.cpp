#include<stdio.h>
#include<string.h>
int main()
{
    char a[1000];
    char b[1000];
    int i=1,j,k=0;
    scanf("%s",a);
    scanf("%s",b);
    j=strlen(a);
    for(i=0;i+1<j;i++)
    {
        if(a[i]!=b[i])
        {
            switch(a[i])
            {
                case '*':a[i]='o';break;
                case 'o':a[i]='*';break;
            }
            switch(a[i+1])
            {
                case '*':a[i+1]='o';break;
                case 'o':a[i+1]='*';break;
            }
            k=k+1;
        }
    }   
    printf("%d",k);
}
