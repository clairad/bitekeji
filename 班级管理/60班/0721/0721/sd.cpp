#include <stdio.h>
#define ARRSIZE(a) (sizeof(a) / sizeof(a[0]))

void dealMSort(int * src, int * tmp, int start, int end)
{
	if (start >= end)
	{
		return;
	}
	
	int mid = (start + end) / 2; 
	dealMSort(src, tmp, start, mid);
	dealMSort(src, tmp, mid + 1, end);
	
	int a = start, b = mid + 1, c = start;
	
	for (; a <= mid && b <= end; c++)
	{
		if (src[a] > src[b])
		{
			tmp[c] = src[b];
			b++;
		}
		else
		{
			tmp[c] = src[a];
			a++;
		}
	}
	
	for (; a <= mid; c++, a++)
	{
		tmp[c] = src[a];
	}
	
	for (; b <= end; c++, b++)
	{
		tmp[c] = src[b];
	}
	
	int i;
	for (i = start; i <= end; i++)
	{
		src[i] = tmp[i];
	}
}

void mergeSort(int * src, int n)
{
	int * tmp = new int [n];
	
	dealMSort(src, tmp, 0, n - 1);
	
	delete [] tmp;
}

void printArray(int * src, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%d ", src[i]);
	}
	putchar('\n');
}

int main()
{
	int src[] = {9, 6, 2, 7, 8, 5, 3, 1};
	int i;
	
	mergeSort(src, ARRSIZE(src));
	
	printArray(src, ARRSIZE(src));
	
	return 0;
}
