#include "sort.h"

#define SWAP(a, b, tmp) {     \
					 tmp = a; \
					 a = b;   \
					 b = tmp  \
					}

void dealMergeSort(int * arr, int * tmp, int start, int end)
{
	if (start >= end) //到了叶子
	{
		return;
	}
	int mid = (start + end) / 2; //分左右子树
	dealMergeSort(arr, tmp, start, mid); //遍历左子树
	dealMergeSort(arr, tmp, mid + 1, end); //遍历右子树
	//其实这是一个二叉树的后序遍历

	int a = start;
	int b = mid + 1;
	int c = a;
	for (; a <= mid && b <= end; c++) //当a和b其中一个的元素已经完全拷贝到c中时，循环跳出
	{
		if (arr[a] >= arr[b])
		{
			tmp[c] = arr[b];
			b++;
		}
		else
		{
			tmp[c] = arr[a];
			a++;
		}
	}

	for (; a <= mid; a++, c++) //如果跳出的是b，那么把a剩下的拷贝到c里
	{
		tmp[c] = arr[a];
	}

	for (; b <= end; b++, c++) //如果跳出的是a，那么把b剩下的拷贝到c里
	{
		tmp[c] = arr[b];
	}

	int i;
	for (i = start; i <= end; i++) //a和b本质上是一个数组，就是原数组，c是临时空间，最后把c的值拷贝回原数组
	{
		arr[i] = tmp[i];
	}
}

void mergeSort(int * arr, int n)
{
	int * tmp = (int *)malloc(n * sizeof(int));

	dealMergeSort(arr, tmp, 0, n - 1);

	free(tmp);
}

void swapArgs(int * a, int * b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void dealQSort(int * arr, int start, int end)
{
	int flag = 1;

	if (start >= end)
	{
		return;
	}

	int i = start, j = end;
	while (i < j)
	{
		if (arr[i] > arr[j])
		{
			swapArgs(arr + i, arr + j);
			flag = !flag;
		}

		flag ? j-- : i++;
	}

	dealQSort(arr, start, i - 1);
	dealQSort(arr, i + 1, end);
}

void QSort(int * arr, int n)
{
	dealQSort(arr, 0, n - 1);
}