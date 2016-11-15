#include<stdio.h>
main()
{	char a[20],b;
	/*fgets(a);
	printf("%s",a);
	scanf("%s",a);
	printf("%s",a);*/
	while((b=getchar())!='\n')
			putchar(b);
}
