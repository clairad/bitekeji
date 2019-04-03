#include <stdio.h>

void printform(int n)
{
	int i, j;
	

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= i; j++)
		{
			printf("%d*%d=%-2d ", j, i, i * j);
		}
		putchar('\n');
	}
}

int main61()
{
	int n, i, j;

	scanf("%d", &n);
	printform(n);

	system("pause");
	return 0;
}