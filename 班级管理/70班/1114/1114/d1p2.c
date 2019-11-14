#include <stdio.h>

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

int d1p3pp()
{
	int n = 6;

	int i, j;

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= i; j++)
		{
			putchar('*');
		}
		putchar('\n');
	}

	return 0;
}