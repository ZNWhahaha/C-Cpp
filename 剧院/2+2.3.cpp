#include<stdio.h>
#include<string.h>
void sizeofapp(char *a)
{	printf("%d %d %d\n",sizeof(a),sizeof(*a),strlen(a));
}
int main()
{	char str1[]="1";
	char str2[]="11";
	printf("sizeof(str2)=%d\n",sizeof(str2));
	sizeofapp(str1);
	sizeofapp(str2);
	return 0;
}
