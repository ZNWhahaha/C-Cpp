#include<stdio.h>
main()
{	int a[50],i,j,k,n,sum;
	scanf("%d",&n);
	for(i=2;i<=n;i++)
	{	k=0;
		sum=0;
		for(j=1;j<i;j++)
		{	if(i%j==0)
			{	a[k]=j;
				k++;
			}
		}
		for(j=0;j<k;j++)
			sum+=a[j];
		if(i==sum)
		{	printf("%d its factors are ",i);
			for(j=0;j<k;j++)
			{	if(j<k-1)
					printf("%d ",a[j]);
				else if(j==k-1)
					printf("%d \n",a[j]);
			}
		}
	}
}
/*һ�������ǡ�õ�����������֮�ͣ�������ͳ�Ϊ"����"�� ���磬6������Ϊ1��2��3����6=1+2+3�����6��"����"�� ������ҳ�N֮�ڵ��������������������ʽ��������ӣ�*/
