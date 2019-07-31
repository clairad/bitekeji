#include "sort.h"
#include "stack.h"

void dealQSort(int * arr, int start, int end)
{
	int flag = 1;

	if (start >= end)
	{
		return;
	}

	int tmp = arr[start];

	int i = start, j = end;
	while (i < j)
	{
		if (flag && tmp > arr[j])
		{
			arr[i] = arr[j];
			flag = !flag;
		}

		if (!flag && tmp < arr[i])
		{
			arr[j] = arr[i];
			flag = !flag;
		}

		flag ? j--: i++;
	}
	arr[i] = tmp;

	dealQSort(arr, start, i - 1);
	dealQSort(arr, i + 1, end);
}

void QSort(int * arr, int n)
{
	dealQSort(arr, 0, n - 1);
}


void swapArgs(int * a, int * b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int Partition(int * arr, int start, int end)
{
	int mid = (start + end) / 2;

	if (arr[start] > arr[mid])
	{
		swapArgs(arr + start, arr + mid);
	}
	if (arr[mid] > arr[end])
	{
		swapArgs(arr + mid, arr + end);
	}
	if (arr[start] > arr[mid])
	{
		swapArgs(arr + start, arr + mid);
	}

	if (end - start <= 2)
	{
		return mid;
	}

	swapArgs(arr + mid, arr + end - 1);

	int i = start + 1;
	int j = end - 2;

	while (arr[i] < arr[end - 1])
	{
		i++;
	}

	while (arr[j] > arr[end - 1])
	{
		j--;
	}

	while (i < j)
	{
		swapArgs(arr + i, arr + j);
		j--, i++;

		while (arr[i] < arr[end - 1])
		{
			i++;
		}

		while (arr[j] > arr[end - 1])
		{
			j--;
		}
	}

	swapArgs(arr + i, arr + end - 1);
	return i;
}


void dealHQSort(int * arr, int start, int end)
{
	if (end - start > INSERT_SORT_LENTH)
	{
		int pivot = Partition(arr, start, end);
		dealHQSort(arr, start, pivot - 1);
		dealHQSort(arr, pivot + 1, end);
	}
	else
	{
		InsertSort(arr + start, end - start + 1);
	}
}

void HQSort(int * arr, int n)
{
	dealHQSort(arr, 0, n - 1);
	//QuickSortNonR(arr, 0, n - 1);
}

void InsertSort(int * arr, int n)
{
	int i, j;
	int tmp;

	for (i = 1; i < n; i++)
	{
		tmp = arr[i];

		for (j = i; j > 0 && arr[j - 1] > tmp; j--)
		{
			arr[j] = arr[j - 1];
		}

		arr[j] = tmp;
	}
}

void ShellSort(int * arr, int n)
{
	int i, j, k;
	int tmp;
	int gap = n / 2;

	for (;gap > 0; gap /= 2)
	{ 
		for (k = 0; k < gap; k++)
		{ 
			for (i = k + gap; i < n; i += gap)
			{
				tmp = arr[i];

				for (j = i; j > 0 && arr[j - gap] > tmp; j -= gap)
				{
					arr[j] = arr[j - gap];
				}

				arr[j] = tmp;
			}
		}
	}
}

void QuickSortNonR(int* a, int left, int right)
{
	Stack st;
	
	StackInit(&st, 100);

	StackPush(&st, left);
	StackPush(&st, right);

	while (StackIsEmpty(&st) == 0)
	{
		int end = StackFront(&st);
		StackPop(&st);
		int begin = StackFront(&st);
		StackPop(&st);
		int div = Partition(a, begin, end);
		if (begin < div - 1)
		{
			StackPush(&st, begin);
			StackPush(&st, div - 1);
		}

		if (div + 1 < end)
		{
			StackPush(&st, div + 1);
			StackPush(&st, end);
		}
	}
}