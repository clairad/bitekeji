#include <stdio.h>

int d1p1()
{
	int a = 5, b = 6;

	printf("a = %d, b = %d\n", a, b);

	/*int tmp;

	tmp = a;
	a = b;
	b = tmp;*/

	a = a + b;
	b = a - b;
	a = a - b;

	printf("a = %d, b = %d\n", a, b);
	return 0;
}