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

int d7p1()
{
	int n;
	scanf("%d", &n);
	
	printMulForm(n);
	return 0;
}