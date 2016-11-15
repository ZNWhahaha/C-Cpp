#include<stdio.h>
int main(void)
{
    char ch;
    int char_num=0,kongge_num=0,int_num=0,other_num=0;
    while((ch=getchar())!='\n')
    if(ch>='a'&&ch<='z'||ch<='z'&&ch>='a')
        {
            char_num++;
        }
    else if(ch==' ')
        {
            kongge_num++;
        }
    else if(ch>='0'&&ch<='9')
        {
            int_num++;
        }
    else
        {
            other_num++;
        }
    printf("%d %d %d %d",char_num,int_num,kongge_num,other_num);
    return 0;
}
