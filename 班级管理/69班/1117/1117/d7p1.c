#include <stdio.h>

void printMulForm(int n)
{
	int i, j;

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= i; j++)
		{
			printf("%d*%d=%d ", j, i, i * j);
		}
		putchar('\n');
	}
}

int main()
{
	printMulForm(12);
	return 0;
}