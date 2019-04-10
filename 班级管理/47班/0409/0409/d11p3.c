#include <stdio.h>

void printArray(int * arr, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	putchar('\n');
}

int main()
{
	int data[10];
	int i, j, n = 10;

	data[0] = 1;
	puts("1");
	for (i = 1; i < n; i++)
	{
		data[i] = 1;
		for (j = i - 1; j > 0; j--)
		{
			data[j] += data[j - 1];
		}
		data[0] = 1;

		printArray(data, i + 1);
	}
	system("pause");
	return 0;
}


int _main()
{
	int data[20][20] = { 0 };
	data[0][0] = 1;
	int i, j, n = 10;

	for (i = 1; i < n; i++)
	{
		data[i][0] = 1;
		for (j = 1; j < i; j++)
		{
			data[i][j] = data[i - 1][j - 1] + data[i - 1][j];
		}
		data[i][j] = 1;
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j <= i; j++)
		{
			printf("%d ", data[i][j]);
		}
		putchar('\n');
	}

	system("pause");
	return 0;
}