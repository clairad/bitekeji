#include <stdio.h>
#include "sort.h"
#define ARRSIZE(a) (sizeof(a) / sizeof(a[0]))
#include "stdlib.h"
#include "time.h"


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
	int a[] = { 7, 4, 2, 1, 8, 9, 3, 6, 5, 10 };
	const int MAX = 1000000;

	int * data = (int *)malloc(MAX * sizeof(int));

	srand((unsigned int)time(NULL));

	int i;
	for (i = 0; i < MAX; i++)
	{
		data[i] = rand() % 10000;
	}

	HQSort(data, MAX);

	printArray(data, MAX);

	free(data);
	return 0;
}
