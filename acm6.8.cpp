#include<stdio.h>
main()
{	int i,n,t,zi=2,mu=1;
	float sum=0.0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{	sum+=(zi*1.0)/mu;
		t=zi;
		zi=zi+mu;
		mu=t;
	}
	printf("%.2f",sum);
}
/*��һ�������У� 2/1 3/2 5/3 8/5 13/8 21/13...... ���������е�ǰN��֮�ͣ�������λС���� */
