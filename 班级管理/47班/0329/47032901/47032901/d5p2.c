#include <stdio.h>

int searchArray(int arr[], int size, int f)
{
	int i;
	for (i = 0; i < size; i++)
	{
		if (arr[i] == f)
		{
			return i;
		}
	}
	return -1;
}

int halfSearchArray(int arr[], int size, int f)
{
	int left = 0;
	int right = size - 1;
	int mid;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (arr[mid] > f)
		{
			right = mid - 1;
		}
		else if (arr[mid] < f)
		{
			left = mid + 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}

int main2()
{
	int a[10] = { 1, 3, 4, 7, 8, 10, 12, 14, 16, 17 };

	printf("%d\n", halfSearchArray(a, 10, 12));
	system("pause");
	return 0;
}