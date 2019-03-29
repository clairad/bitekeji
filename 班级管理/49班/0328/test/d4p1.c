#include <stdio.h>
#include <string.h>

int main1()
{
	int n;
	int i, j;

	scanf("%d", &n);

	for (i = 1; i <= n; i++)
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

	for (i = n - 1; i >= 1; i--)
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

	system("pause");
	return 0;
}