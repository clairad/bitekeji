#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"
#define BUFSIZE 1000000

void printArray(int * src, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%d ", src[i]);
	}
	putchar('\n');
}

int src[BUFSIZE];
int main()
{
#if 0
	//int src[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int src[11] = { 3, 1, 6, 7, 9, 2, 4, 8, 10, 5, 11 };

	QuickSort(src, 11);

	printArray(src, 11);
#else
	srand(time(NULL));

	int i;
	for (i = 0; i < BUFSIZE; i++)
	{
		src[i] = rand() % 5000 + 1;
	}

	//QuickSort(src, BUFSIZE); 
	//MergeSort(src, BUFSIZE);
	//ShellSort(src, BUFSIZE);
	//InsertSort(src, BUFSIZE);
	QuickSortNonR(src, BUFSIZE);
	printArray(src, BUFSIZE);
#endif
	return 0;
}

