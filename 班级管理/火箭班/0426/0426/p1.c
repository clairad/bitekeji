#include <stdio.h>
#define MAX(a, b) ((a) > (b) ? (a) : (b))

void fillForm(int a[][50], int x, int y)
{
	int i, j;

	for (i = 1; i <= x; i++)
	{
		for (j = 1; j <= y; j++)
		{
			if (i == 1 && j == 1)
			{
				a[i][j] = 1;
			}
			else
			{
				a[i][j] = a[i - 1][j] + a[i][j - 1];
			}
		}
	}
}

void fillForm2(int a[][50], int x, int y, int x2, int y2)
{
	int i, j;

	for (i = 1; i <= x; i++)
	{
		for (j = 1; j <= y; j++)
		{
			if (i == x2 && j == y2)
			{
				continue;
			}

			if (i == 1 && j == 1)
			{
				a[i][j] = 1;
			}
			else
			{
				a[i][j] = a[i - 1][j] + a[i][j - 1];
			}
		}
	}
}

void fillForm3(int a[][5], int x, int y)
{
	int i, j;

	for (i = 1; i <= x; i++)
	{
		for (j = 1; j <= y; j++)
		{
			a[i][j] += MAX(a[i - 1][j], a[i][j - 1]);
		}
	}
}

int main1()
{
	int a[50][5] = { 0, 0, 0, 0, 0,
					  0, 1, 15, 6, 9,
					  0, 4, 3, 7, 12,
					  0, 16, 14, 8, 11,
					  0, 10, 5, 2, 13, };
	int x, y;
	int x2, y2;
	//scanf("%d%d", &x, &y);
	//scanf("%d%d", &x2, &y2);

	//fillForm(a, x, y);
	//fillForm2(a, x, y, x2, y2);
	fillForm3(a, 4, 4);
	printf("%d", a[4][4]);
	return 0;
}