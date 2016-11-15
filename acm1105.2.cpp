#include <stdio.h>
#include <math.h>
long int sum = 0;
int i=1;
long int print(int x,int n)
{		long int temp;
    if(i>n)
        return sum;
    else
	{   temp=pow(x,i);
        if(i%2==0)
            temp=-temp;
        sum =sum+temp;
    }
    i++;
    return print(x,n);
}
int main() 
{
    float x;
    int n;
    scanf("%f,%d",&x,&n);
    printf("%ld",print(x,n));
    return 0;
}

