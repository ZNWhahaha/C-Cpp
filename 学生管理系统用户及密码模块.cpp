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
  printf("��ǰû���κ��û�\n");
        printf("���½��û����� ");
     scanf("%s",s);
      printf("Ϊ�û��������룺 ");
     scanf("%s",d);
        strcpy(z.a,s);
        strcpy(z.b,d);
        fprintf(p,"%s %s",z.a,z.b);
     fclose(p);
 }
 if(t==0)
 {
    printf("�������û����� ");
    scanf("%s",s);
       fscanf(p,"%s %s",z.a,z.b);
       fclose(p);
       if (!strcmp(z.a,s))
    {
        printf("���������룺");
     scanf("%s",d);getchar();
           if(!strcmp(z.b,d))
     {  char i;
              printf("�Ƿ�Ҫ�޸����룿������y�޸ģ�n�˳�����");
              scanf("%c",&i);
              if(i=='y')
     {   
                  printf("�������޸����룺");
               scanf("%s",z.b);
                  p=fopen("m.txt","w+");
                  fprintf(p,"%s %s",z.a,z.b);
      fclose(p);
               printf("�޸ĳɹ���");
   
   }

}
     else printf("�������");
    }
    else printf("�û�������");
       fclose(p);
 
 }

}
