#include <stdio.h>

int d4p1()
{
	int n = 5;
	int i, j;

	for (i = 1; i < n; i++)
	{
		for (j = 1; j <= n - i; j++)
		{
			putchar(' ');
		}

		for (j = 1; j <= 2 * i - 1; j++)
		{
			putchar('*');
		}
		putchar('\n');
	}

	for (i = n; i > 0; i--)
	{
		for (j = 1; j <= n - i; j++)
		{
			putchar(' ');
		}

		for (j = 1; j <= 2 * i - 1; j++)
		{
			putchar('*');
		}
		putchar('\n');
	}

	return 0;
}

int d1p2()
{
	int n = 9;

	int i, j;

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= i; j++)
		{
			printf("%d*%d=%d ", j, i, i * j);
		}
		putchar('\n');
	}

	return 0;
}