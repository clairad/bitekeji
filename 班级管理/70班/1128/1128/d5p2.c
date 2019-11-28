#include <stdio.h>

int binaryFind(int src[], int n, int f)
{
	int left = 0;
	int right = n - 1;
	int mid;

	while (left <= right)
	{
		mid = (left + right) / 2;
		if (src[mid] > f)
		{
			right = mid - 1;
		}
		else if (src[mid] < f)
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

int d5p2()
{
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	printf("%d", binaryFind(arr, 10, 11));

	return 0;
}

//string.h
//int strcmp(const char * s1, const char * s2);
// s1 > s2  ·µ»Ø1
// s1 == s2 ·µ»Ø0
// s1 < s2  ·µ»Ø-1