#include <stdio.h>

int d3p1()
{
	int a[5] = { 1, 2, 3, 4, 5 };
	int b[5] = { 5, 6, 7, 8, 9 };

	int i;
	int tmp;
	for (i = 0; i < 5; i++)//±éÀú
	{
		tmp = a[i];
		a[i] = b[i];
		b[i] = tmp;
	}

	for (i = 0; i < 5; i++)
	{
		printf("%d ", a[i]);
	}
	putchar('\n');

	for (i = 0; i < 5; i++)
	{
		printf("%d ", b[i]);
	}
	putchar('\n');
	return 0;
}

int d2p12()
{
	int a = 5, b = 6;

	printf("a = %d, b = %d\n", a, b);
	/*
	int tmp;
	tmp = a;
	a = b;
	b = tmp;
	*/

	a = a + b;
	b = a - b;
	a = a - b;

	printf("a = %d, b = %d\n", a, b);

	return 0;
}