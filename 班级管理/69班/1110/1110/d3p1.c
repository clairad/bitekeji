#include <stdio.h>

int d3p1()
{
	int a[5] = { 1, 2, 3, 4, 5 };
	int b[5] = { 5, 6, 7, 8, 9 };

	int i;
	for (i = 0; i < 5; i++) //数组遍历
	{
		printf("%d ", a[i]);
	}
	putchar('\n');
	for (i = 0; i < 5; i++) //数组遍历
	{
		printf("%d ", b[i]);
	}
	putchar('\n');

	int tmp;
	for (i = 0; i < 5; i++) //数组遍历
	{
		tmp = a[i];
		a[i] = b[i];
		b[i] = tmp;
	}

	for (i = 0; i < 5; i++) //数组遍历
	{
		printf("%d ", a[i]);
	}
	putchar('\n');
	for (i = 0; i < 5; i++) //数组遍历
	{
		printf("%d ", b[i]);
	}
	putchar('\n');

	return 0;
}