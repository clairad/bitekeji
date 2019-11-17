#include <stdio.h>

int binaryFind(int arr[], int n, int f)
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

int d5p2()
{
	int arr[10] = { 2, 5, 7, 10, 12, 15, 19, 20, 26, 28 };

	printf("%d", binaryFind(arr, 10, 16));

	return 0;
}

/*
int strcmp(const char * s1, const char * s2);
>

char * strcpy(char * dst, const char * src);
=

char * strcat(char * dst, const char * src);
+=

*/