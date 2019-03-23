#include <stdio.h>

struct test {
	int a;
	int b;
};

union test2 {
	int a;
	int b;
};

int _main()
{
	int a[5];
	union test2 u;
	/*
	printf("%d\n", sizeof(int));
	printf("%d\n", sizeof(int [5]));
	printf("%d\n", sizeof(struct test));
	printf("%d\n", sizeof(union test2));
	u.a = 100;
	printf("%d\n", u.b);*/

	int i = 100; 
	int * pi = &i;
	char c = 'A';
	char * pc = &c;
	void * pa = pi;

	printf("%d\n", *(int *)pa);
	pa = pc;
	printf("%c\n", *(char *)pa);

	system("pause");
	return 0;
}