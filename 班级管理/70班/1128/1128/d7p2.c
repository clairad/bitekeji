#include <stdio.h>

void swap(int * pa, int * pb)
{
	int tmp;

	tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}

void test(int * pa, int * pb)
{
	int * ptmp;

	ptmp = pa;
	pa = pb;
	pb = ptmp;
}

int main()
{
	int a = 5, b = 6;
	test(&a, &b);

	printf("%d %d", a, b);
	return 0;
}