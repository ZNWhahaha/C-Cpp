#include <stdio.h>
int main()
{
	int n,i,j,sum,num[50],t=0;
	char str[10];
	scanf("%d", &n);
	for(i = 10000; i < 1000000; i++)
	{
		sprintf(str, "%d", i);
		sum = 0;
		for(j = 0; str[j]; j++)
			sum += str[j] - '0';
		if(sum != n)
			continue;
		if(i < 100000 && str[0] == str[4] && str[1] == str[3])
		{	num[t]=i;
			t++;
		}
		else if(i >= 100000 && str[0] == str[5] && str[1] == str[4] && str[2] == str[3])
		{	num[t]=i;
			t++;
		}
	}
	if(t>10)
		printf("%d",t);
	if(t<=10)
		for(i=0;i<t;i++)
		{	printf("%d",num[i]);
			if(i!=(t-1))
				printf("\n");
		}
	return 0;
}
