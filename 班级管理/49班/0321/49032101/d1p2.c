#include <stdio.h>

int main0()
{
	int i, j;
	int n = 9;

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= i; j++)
		{
			printf("%d*%d=%d ", j, i, i * j);
		}
		putchar('\n');
	}

	system("pause");
	return 0;
}