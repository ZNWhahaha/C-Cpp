#include<stdio.h>
main(void)
{
    int N,i;
    float M,h,s=0,b;
    scanf("%f %d",&M,&N);
    b=M/2;
    for (i=2;i<=N;i++)
    {	h=b/2;
        b=h;
        s+=4*b;
     }
    printf("%.2f %.2f",h,s+M);
}

