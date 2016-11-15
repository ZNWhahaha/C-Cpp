#include<stdio.h>
#include<math.h>
int main(void)
{
    int n,x=0,y=0,z=0;
    scanf("%d",&n);
    while(x<n)
    {
        y=y+2*pow(10,x);
        z=z+y;
        x++;
    }
    printf("%d",z);
 } 
