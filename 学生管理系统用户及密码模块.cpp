#include <stdio.h>
#include <string.h>
struct e
{
  char a[10];
  char b[10];
}z;
int main()
{   int t=0;
    char s[10],d[10];
    FILE *p;
 void as();
    if ((p=fopen("m.txt","r+"))==NULL) 
 {
  p=fopen("m.txt","w+");
  t=1;
 }
 if(t==1)
 {
  printf("当前没有任何用户\n");
        printf("请新建用户名： ");
     scanf("%s",s);
      printf("为用户设置密码： ");
     scanf("%s",d);
        strcpy(z.a,s);
        strcpy(z.b,d);
        fprintf(p,"%s %s",z.a,z.b);
     fclose(p);
 }
 if(t==0)
 {
    printf("请输入用户名： ");
    scanf("%s",s);
       fscanf(p,"%s %s",z.a,z.b);
       fclose(p);
       if (!strcmp(z.a,s))
    {
        printf("请输入密码：");
     scanf("%s",d);getchar();
           if(!strcmp(z.b,d))
     {  char i;
              printf("是否要修改密码？（输入y修改，n退出！）");
              scanf("%c",&i);
              if(i=='y')
     {   
                  printf("请输入修改密码：");
               scanf("%s",z.b);
                  p=fopen("m.txt","w+");
                  fprintf(p,"%s %s",z.a,z.b);
      fclose(p);
               printf("修改成功！");
   
   }

}
     else printf("密码错误！");
    }
    else printf("用户名错误");
       fclose(p);
 
 }

}
