#include<stdio.h> 
main() 
{ 
 int i,j,n,t=1,a[20][20],m; 
  scanf("%d",&n); 
 if(n%2==0) m=n/2; 
 else  m=n/2+1; 
 for(i=0;i<m;i++) 
  { 
   for(j=i;j<n-i;j++) 
     { 
      a[i][j]=t; 
      t++;} 
   for(j=i+1;j<n-i;j++) 
     {a[j][n-i-1]=t; 
      t++; } 
   for(j=n-i-2;j>=i;j--) 
     {a[n-i-1][j]=t; 
      t++;} 
   for(j=n-i-2;j>=i+1;j--) 
     {a[j][i]=t;t++;} 
  } 
 for(i=0;i<n;i++) 
  {for(j=0;j<n;j++) 
    printf("%d ",a[i][j]); 
    printf("\n"); 
  } 
}
