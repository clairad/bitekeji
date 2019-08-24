#include "sort.h"
#include "queue.h"
#include <stdlib.h>


void InsertSort(int * src, int n)
{
	int i, j;
	int tmp;

	for (i = 1; i < n; i++)
	{
		tmp = src[i];

		for (j = i; j > 0 && src[j - 1] > tmp; j--)
		{
			src[j] = src[j - 1];
		}

		src[j] = tmp;
	}
}

void ShellSort(int * src, int n)
{
	int i, j, k;
	int gap, tmp;

	for (gap = n / 2; gap; gap /= 2)
	{ 
		for (k = 0; k < gap; k++)
		{
			for (i = gap + k; i < n; i += gap)
			{
				tmp = src[i];

				for (j = i; j >= gap && src[j - gap] > tmp; j -= gap)
				{
					src[j] = src[j - gap];
				}

				src[j] = tmp;
			}
		}
	}
}

void dealMergeSort(int * src, int * tmp, int start, int end)
{
	if (start >= end)
	{
		return;
	}

	int mid = (start + end) / 2;
	dealMergeSort(src, tmp, start, mid);
	dealMergeSort(src, tmp, mid + 1, end);

	int a = start;
	int b = mid + 1;
	int c = start;
	while (a <= mid && b <= end)
	{
		if (src[a] < src[b])
		{
			tmp[c] = src[a];
			a++;
		}
		else
		{
			tmp[c] = src[b];
			b++;
		}
		c++;
	}

	for (; a <= mid; a++, c++)
	{
		tmp[c] = src[a];
	}

	for (; b <= end; b++, c++)
	{
		tmp[c] = src[b];
	}

	int i;
	for (i = start; i <= end; i++)
	{
		src[i] = tmp[i];
	}
}

void MergeSort(int * src, int n)
{
	int * tmp = (int *)malloc(n * sizeof(int));

	dealMergeSort(src, tmp, 0, n - 1);

	free(tmp);
}

void swapArgs(int *pa, int *pb)
{
	int tmp;

	tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}

int HoareWay(int * src, int start, int end)
{
	int a = start + 1, b = end - 2;
	int mid = (start + end) / 2;

	if (src[start] > src[mid])
	{
		swapArgs(src + start, src + mid);
	}
	if (src[mid] > src[end])
	{
		swapArgs(src + mid, src + end);
	}
	if (src[start] > src[mid])
	{
		swapArgs(src + start, src + mid);
	}

	if (end - start <= 2)
	{
		return mid;
	}

	swapArgs(src + mid, src + end - 1);

	while (a <= b)
	{
		while (a < end - 1 && src[a] <= src[end - 1])
		{
			a++;
		}

		while (b > 1 && src[b] >= src[end - 1])
		{
			b--;
		}

		if (a == b && (a == 1 || a == end - 1))
		{
			break;
		}

		if (a < b)
		{
			swapArgs(src + a, src + b);
		}
	}
	swapArgs(src + a, src + end - 1);
	return a;
}

int digWay(int * src, int start, int end)
{
	int a = start, b = end;
	int flag = 0;
	int tmp = src[start];

	while (1)
	{
		while (b > start && src[b] >= tmp)
		{
			b--;
		}

		if (a < b)
		{ 
			src[a] = src[b];
		}
		else
		{
			src[a] = tmp;
			return a;
		}

		while (a < end && src[a] <= tmp)
		{
			a++;
		}

		if (a < b)
		{ 
			src[b] = src[a];
		}
		else
		{
			src[b] = tmp;
			return b;
		}
	}
}

int doublePointerWay2(int * src, int start, int end)
{
	int a = start, b = end - 1;
	int mid = (start + end) / 2;

	swapArgs(src + mid, src + end);

	while (a <= b)
	{
		while (a < end && src[a] <= src[end])
		{
			a++;
		}

		while (b > 0 && src[b] >= src[end])
		{
			b--;
		}

		if (a == b && (a == 0 || a == end))
		{
			break;
		}

		if (a < b)
		{ 
			swapArgs(src + a, src + b);
		}
	}
	swapArgs(src + a, src + end);
	return a;
}

int doublePointerWay1(int * src, int start, int end)
{
	int a = start, b = end;
	int flag = 0;

	while (src[b] > src[a])
	{
		b--;
	}

	while (a < b)
	{
		swapArgs(src + b, src + a);
		flag = !flag;

		while (src[b] >= src[a])
		{
			flag ? a++ : b--;
		}
	}

	return flag ? b : a;
}

void dealQuickSort(int * src, int start, int end)
{
	int mid;
	if (start + 8 < end)
	{
		mid = HoareWay(src, start, end);
		dealQuickSort(src, start, mid - 1);
		dealQuickSort(src, mid + 1, end);
	}
	else
	{
		InsertSort(src + start, end - start + 1);
	}
}

void QuickSort(int * src, int n)
{
	dealQuickSort(src, 0, n - 1);
}

void QuickSortNonR(int * src, int n)
{
	int start, end;
	int mid;
	Queue qu;

	QueueInit(&qu);

	QueuePush(&qu, 0);
	QueuePush(&qu, n - 1);

	while (!QueueIsEmpty(&qu))
	{
		start = QueueTop(&qu);
		QueuePop(&qu);
		end = QueueTop(&qu);
		QueuePop(&qu);
		mid = HoareWay(src, start, end);

		if (start < mid - 1)
		{
			QueuePush(&qu, start);
			QueuePush(&qu, mid);
		}

		if (mid + 1 < end)
		{
			QueuePush(&qu, mid + 1);
			QueuePush(&qu, end);
		}
	}

	QueueDestory(&qu);
}