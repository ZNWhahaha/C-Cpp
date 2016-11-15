#include<stdio.h>
struct	stu
{	int a;
	char b;
	short c;
};
struct stun
{	char b;
	int a;
	short c;
};
main()
{	struct stu A;
	struct stun B;
	printf("%d %d",sizeof(A),sizeof(B));
	printf("\n%d %d %d",sizeof(int),sizeof(char),sizeof(short));
}
