#include <stdio.h>

struct Test{
	char a;
	short b;
	int c;
};

int main()
{
	struct Test t;

	printf("%p\n%p\n%p\n%p\n", &t, &t.a, &t.b, &t.c);

	return 0;
}