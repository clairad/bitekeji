#include <stdio.h>

int findNum(int a[][3], int x, int y, int f)
{
	int i = 0, j = y - 1;

	while (i < x && y >= 0)
	{
		if (a[i][j] > f)
		{
			j--;
		}
		else if (a[i][j] < f)
		{
			i++;
		}
		else
		{
			return 1;
		}
	}
	return 0;
}

int main()
{
	int a[][3] = { { 1, 3, 5 },
				   { 3, 5, 7 },
				   { 5, 7, 9 } };
	if (findNum(a, 3, 3, 7))
	{
		printf("找到了\n");
	}
	else
	{
		printf("没找到\n");
	}

	return 0;
}