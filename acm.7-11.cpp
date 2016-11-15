#include<stdio.h> 
main() 
{ 
  int m,i,a[12]; 
  char b[12][10]={"January","February","March","April","May","June","July","Auguest","Sepetmber","October","November","December"}; 
   for(i=0;i<12;i++) 
   { scanf("%d",&a[i]); 
   if(a[i]==0) 
       break; 
   else if(a[i]>0&&a[i]<13) 
  
     printf("%s\n",b[a[i]-1]); 
   else
     printf("error\n"); 
   } 
} 
