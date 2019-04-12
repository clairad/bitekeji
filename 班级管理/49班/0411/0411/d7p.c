#include <stdio.h>

void printNum(int * data, int n, int k, int sum, int start)
{
	if (k == 0)
	{
		printf("%d\n", sum);
		return;
	}
	int i;
	for (i = start; i < n; i++)
	{
		printNum(data, n, k - 1, sum + data[i], i + 1);
	}
}

int main()
{
	int num[5] = { 1, 2, 3, 4, 5 };

	printNum(num, 5, 3, 0, 0);

	/*
	int i, j, k;

	for (i = 0; i < 3; i++)
	{
		for (j = i + 1; j < 4; j++)
		{
			for (k = j + 1; k < 5; k++)
			printf("%d + %d + %d = %d\n", num[i], num[j], num[k], num[i] + num[j] + num[k]);
		}
	}*/

	return 0;
}