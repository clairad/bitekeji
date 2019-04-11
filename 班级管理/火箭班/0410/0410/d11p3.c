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

int main113()
{
	int n = 10;
	int i, j;
#if 0
	int data[20][20] = { 0 };
	printf("%d\n", data[0][0] = 1);
	for (i = 1; i < n; i++)
	{
		printf("%d ", data[i][0] = 1);
		for (j = 1; j < i; j++)
		{
			printf("%d ", data[i][j] = data[i - 1][j - 1] + data[i - 1][j]);
		}
		printf("%d\n", data[i][j] = 1);
	}
#else
	int data[20] = {1, 1};

	puts("1");
	puts("1 1");
	for (i = 2; i < n; i++)
	{
		data[i] = 1;
		for (j = i - 1; j > 0; j--)
		{
			data[j] += data[j - 1];
		}
		printArray(data, i + 1);
	}

#endif
	return 0;
}