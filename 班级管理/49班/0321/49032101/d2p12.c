#include <stdio.h>

int main1()
{
	int a = 3, b = 5;
	int tmp;
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