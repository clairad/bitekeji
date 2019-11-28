#include <stdio.h>

int d4p1()
{
	int n;
	scanf("%d", &n);

	int i, j;

	for (i = 1; i < n; i++)
	{
#if 0
		for (j = 0; j < n - i; j++)
		{
			putchar(' ');
		}

		for (j = 0; j < 2 * i - 1; j++)
		{
			putchar('*');
		}
#else
		for (j = 0; j < i + n - 1; j++)
		{
			putchar(j < n - i ? ' ' : '*');
		}

#endif
		putchar('\n');
	}

	for (i = n; i > 0; i--)
	{
#if 0
		for (j = 0; j < n - i; j++)
		{
			putchar(' ');
		}

		for (j = 0; j < 2 * i - 1; j++)
		{
			putchar('*');
		}
#else
		for (j = 0; j < i + n - 1; j++)
		{
			putchar(j < n - i ? ' ' : '*');
		}

#endif
		putchar('\n');
	}

	return 0;
}