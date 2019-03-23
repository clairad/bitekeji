#include <stdio.h>

int main3()
{
	int a = 5, b = 10, tmp;
	/*
	tmp = a;
	a = b;
	b = tmp;*/

	a = a + b;
	b = a - b;
	a = a - b;

	printf("a = %d, b = %d\n", a, b);
	system("pause");
	return 0;
}