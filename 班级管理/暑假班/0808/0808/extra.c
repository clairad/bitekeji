#include <stdio.h>

void choosenum(int * src, int n, int k, int ans, int start)
{
	if (k == 0)
	{
		printf("%d\n", ans);
		return;
	}
	int i;

	for (i = start; i < n; i++)
	{
		choosenum(src, n, k - 1, ans + src[i], i + 1);
	}
}

int main()
{
	int arr[8] = { 1, 2, 3, 4, 5, 6, 7, 8 };

	choosenum(arr, 8, 4, 0, 0);
	/*
	int i, j, k;

	for (i = 0; i < 5; i++)
	{
		for (j = i + 1; j < 5; j++)
		{
			for (k = j + 1; k < 5; k++)
			{
				printf("%d\n", arr[i] + arr[j] + arr[k]);
			}
		}
	}*/

	return 0;
}