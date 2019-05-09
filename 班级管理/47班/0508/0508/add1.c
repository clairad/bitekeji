#include <stdio.h>

void bubble(int data[], int n)
{
	int i, j, tmp;

	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - 1 - i; j++)
		{
			if (data[j] > data[j + 1])
			{
				tmp = data[j];
				data[j] = data[j + 1];
				data[j + 1] = tmp;
			}
		}
	}
}

int bag()
{
	int size, num;
	int weight[20] = { 0 };
	int i, sum = 0;

	scanf("%d%d", &num, &size);
	for (i = 0; i < num; i++)
	{
		scanf("%d", weight + i);
	}
	bubble(weight, num);

	for (i = 0; sum + weight[i] < size && i < num; i++)
	{
		sum += weight[i];
	}

	printf("%d", i);
	return 0;
}

int boat()
{
	int size, num;
	int weight[20] = { 0 };
	int i, j, sum = 0, count = 0;

	scanf("%d%d", &num, &size);
	for (i = 0; i < num; i++)
	{
		scanf("%d", weight + i);
	}
	bubble(weight, num);

	for (i = 0, j = num - 1; i <= j; j--)
	{
		if (weight[i] + weight[j] <= size)
		{
			i++;
		}
		count++;
	}

	printf("%d", count);
	return 0;
}

int stone()
{
	int n;
	int num[20] = { 0 };
	int i, sum = 0;

	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", num + i);
	}

	for (i = 0; i < n - 1; i++)
	{
		bubble(num + i, n - i);

		num[i + 1] = num[i] + num[i + 1];
		sum += num[i + 1];
	}
	
	printf("%d", sum);
	return 0;
}

int count()
{
	int a[10][10] = { 0 };
	int x, y;
	int x2, y2;
	scanf("%d%d", &x, &y);
	scanf("%d%d", &x2, &y2);
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

	printf("%d", a[x][y]);
	return 0;
}

int main()
{
	int a[5][5] = { 0, 0, 0, 0, 0,
					0, 5, 18, 4, 20,
					0, 22, 15, 9, 10,
					0, 14, 16, 12, 21,
					0, 19, 8, 11, 6 };

	int i, j;
	for (i = 1; i <= 4; i++)
	{
		for (j = 1; j <= 4; j++)
		{
			if (a[i - 1][j] > a[i][j - 1])
			{
				a[i][j] += a[i - 1][j];
			}
			else
			{
				a[i][j] += a[i][j - 1];
			}
		}
	}

	printf("%d", a[4][4]);
	return 0;
}

