/*将一个小写英文字符串重新排列,按字符出现的顺序将所有相同字符存放在一起。*/
#include<stdio.h>
#include<string.h>
main()
{	char str,temp[] = {"adcbadbca"},newString[] = {"adcbadbca"}; 
 	int i,j,n,k=0;
	n=strlen(temp); 
 	for(i=0;i<n;i++) 
 	{ 
  		if(temp[i] != '0') 
  		{ 
   			str=temp[i]; 
    		for(int j = 0;j<n;j++) 
  			{  
   				if(temp[j] == str) 
   				{ 
   		  			newString[k++] = temp[j]; 
   		  			temp[j] = '0'; 
   		 		}	 
  		 	} 
  		} 
 	} 
 printf("%s\n",newString);
}
