#include <stdio.h>
#define ROW 5
#define LINE 5

int main1()
{
	int a[22][22] = { 0 };
	int x, y;
	scanf("%d%d", &x, &y);
	int i, j;

	
	for (i = 1; i <= LINE; i++)
	{
		for (j = 1; j <= ROW; j++)
		{
			if (i == x + 1 && j == y + 1)
			{
				continue;
			}

			if (i == 1 && j == 1)
			{
				a[i][j] = 1;
			}
			a[i][j] = a[i - 1][j] + a[i][j - 1];
		}
	}

	for (i = 1; i <= LINE; i++)
	{
		for (j = 1; j <= ROW; j++)
		{
			printf("%d ", a[i][j]);
		}
		putchar('\n');
	}

	printf("%d\n", a[LINE][ROW]);
	return 0;
}