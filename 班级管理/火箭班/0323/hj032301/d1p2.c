#include <stdio.h>

int main2()
{
	int i, j, n = 9;
	//scanf("%d", &n);

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