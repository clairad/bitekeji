#include <stdio.h>
#include <string.h>

void InitArray(int dst[], const int src[], int n)
{/*
	int i;

	for (i = 0; i < n; i++)
	{
		dst[i] = src[i];
	}*/

	memcpy(dst, src, sizeof(int) * n);
}

void ClearArray(int dst[], int n)
{
	memset(dst, 0, sizeof(int) * n);
}

void ReverseArray(int dst[], int n)
{
	int i, j;

	for (i = 0, j = n - 1; i < j; i++, j--)
	{
		swap(&dst[i], &dst[j]);
	}
}

int d7p4()
{
	int a[10];
	int b[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	InitArray(a, b, 10);
	printArray(a, 10);
	ReverseArray(a, 10);
	printArray(a, 10);
	ClearArray(a, 10);
	printArray(a, 10);

	return 0;
}