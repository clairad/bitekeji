#include <stdio.h>

int searchArray(int arr[], int n, int f)
{
	int left = 0;
	int right = n - 1;
	int mid;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (arr[mid] < f)
		{
			left = mid + 1;
		}
		else if (arr[mid] > f)
		{
			right = mid - 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}

int main52()
{
	int a[10] = { 1, 3, 4, 5, 7, 9, 11, 13, 15, 16 };
	printf("%d\n", searchArray(a, 10, 12));

	system("pause");
	return 0;
}