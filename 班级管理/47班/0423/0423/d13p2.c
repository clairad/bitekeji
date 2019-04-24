#include <stdio.h>

int findNum(int a[][3], int x, int y, int f)
{
	int i = 0, j = y - 1;
	while (j >= 0 && i < x)
	{
		if (a[i][j] < f)
		{
			i++;
		}
		else if (a[i][j] > f)
		{
			j--;
		}
		else
		{
			return 1;
		}
	}
	return 0;
}

int main132()
{
	int a[3][4] = { { 1, 3, 5, 7 },
					{ 3, 5, 7, 9 },
					{ 5, 7, 9, 11 } };

	if (findNum(a, 3, 4, 8))
	{
		printf("It has been found!\n");
	}
	else
	{
		printf("It hasn't been found!\n");
	}

	return 0;
}