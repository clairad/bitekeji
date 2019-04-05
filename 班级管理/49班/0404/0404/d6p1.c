#include <stdio.h>

void printMul(int n)
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
	int n;
	int i, j;

	//printf("%06.2lf", 3.14159265);
	scanf("%d", &n);
	printMul(n);

	system("pause");
	return 0;
}