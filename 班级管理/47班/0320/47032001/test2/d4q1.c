#include <stdio.h>

int main3()
{
	int i, j;
	int n;

	scanf("%d", &n);

	for (i = 1; i <= n; i++)
	{
		for (j = 0; j < n - i; j++)
		{
			putchar(' ');
		}

		for (j = 0; j < 2 * i - 1; j++)
		{
			putchar('*');
		}
		putchar('\n');
	}

	for (i = n - 1; i > 0; i--)
	{
		for (j = 0; j < n - i; j++)
		{
			putchar(' ');
		}

		for (j = 0; j < 2 * i - 1; j++)
		{
			putchar('*');
		}
		putchar('\n');
	}
	
	system("pause");
	return 0;
}