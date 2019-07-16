#include <stdio.h>

struct test{
	struct test *pa;
}b;

typedef struct {
	int a;
	int * pa;
}TEST1;

typedef struct {
	int a;
	TEST1 * pt;
}TEST2;

int main()
{
	int a = 5;
	TEST1 t1 = {6, &a};
	TEST2 t2 = {7, &t1};
	
	printf("%d\n", *t2.pt->pa);
	
	return 0;
}
