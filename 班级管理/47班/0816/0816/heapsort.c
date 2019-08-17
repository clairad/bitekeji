#include <stdio.h>

static void adjustDown(int * data, int size, int m)
{
	int cur = m;
	int n;

	while (cur * 2 + 1 < size)
	{
		if (cur * 2 + 2 >= size)
		{
			n = cur * 2 + 1;
		}
		else
		{
			if (data[cur * 2 + 1] > data[cur * 2 + 2])
			{
				n = cur * 2 + 1;
			}
			else
			{
				n = cur * 2 + 2;
			}
		}

		if (data[cur] < data[n])
		{
			int tmp = data[cur];
			data[cur] = data[n];
			data[n] = tmp;

			cur = n;
		}
		else
		{
			break;
		}
	}
}

void swapHeap(int *data, int size)
{
	if (size == 0)
	{
		return;
	}

	int tmp = data[0];
	data[0] = data[size - 1];
	data[size - 1] = tmp;

	adjustDown(data, size - 1, 0);
}

void HeapSortS(int *src, int n)
{
	int i;
	for (i = n / 2 - 1; i >= 0; i--)
	{
		adjustDown(src, n, i);
	}

	for (; n > 1; n--)
	{
		swapHeap(src, n);
	}
}

void printArray(int *arr, int n)
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
	int data[10] = { 6, 2, 5, 4, 1, 9, 8, 10, 7, 3 };

	HeapSortS(data, 10);
	printArray(data, 10);
	return 0;
}