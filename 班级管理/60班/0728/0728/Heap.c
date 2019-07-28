#include "Heap.h"
#include <string.h>
#include <stdio.h>

void swap(HPDataType *a, HPDataType *b)
{
	HPDataType tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void DownAdjust(Heap *hp, int n)
{
	int cur = n;
	while (cur * 2 + 1 < hp->_size) //如果一个堆的节点没有左节点，那么它就是叶子，所以直接跳出
	{
		if (hp->_data[cur] < hp->_data[cur * 2 + 1]) //大根堆中，如果我比的左孩子小，那么要执行交换
		{
			if (cur * 2 + 2 >= hp->_size ||  //如果右孩子不存在，直接交换
				hp->_data[cur * 2 + 1] >= hp->_data[cur * 2 + 2]) //如果左孩子比右孩子大，那么我跟左孩子换
			{
				swap(&hp->_data[cur], &hp->_data[cur * 2 + 1]); //换值
				cur = cur * 2 + 1; //换位
			}
			else //如果右孩子存在且比左孩子还大，那么跟右孩子换
			{
				swap(&hp->_data[cur], &hp->_data[cur * 2 + 2]);
				cur = cur * 2 + 2;
			}
		}
		else if (cur * 2 + 2 < hp->_size && //如果右孩子不存在，就不会比较右孩子
			     hp->_data[cur] < hp->_data[cur * 2 + 2]) //如果比左孩子大，但比右孩子小，那么我跟右孩子换
		{
			swap(&hp->_data[cur], &hp->_data[cur * 2 + 2]);
			cur = cur * 2 + 2;
		}
		else
		{
			break; //如果我比左右孩子都大，那么直接跳出
		}
	}
}

void HeapInit(Heap *hp, HPDataType *a, int n)
{
	int i;

	hp->_capacity = MAXSIZE > n ? MAXSIZE : n;
	hp->_size = n;
	hp->_data = (HPDataType *)malloc(sizeof(HPDataType) * hp->_capacity);
	memcpy(hp->_data, a, sizeof(HPDataType) * n);

	for (i = n / 2 - 1; i >= 0; i--)
	{
		DownAdjust(hp, i);
	}
}

void HeapDestory(Heap *hp)
{
	if (hp->_data)
	{
		free(hp->_data);
		hp->_data = NULL;
		hp->_size = hp->_capacity = 0;
	}
}

void HeapPush(Heap *hp, HPDataType x)
{
	int cur = hp->_size;

	if (hp->_size == hp->_capacity)
	{
		hp->_capacity *= 2;
		hp->_data = (HPDataType *)realloc(hp->_data, hp->_capacity * sizeof(HPDataType));
	}

	hp->_data[hp->_size] = x;
	hp->_size++;

	while (cur)
	{
		if (hp->_data[cur] > hp->_data[(cur - 1) / 2])
		{
			swap(&hp->_data[cur], &hp->_data[(cur - 1) / 2]);
			cur = (cur - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

void HeapPop(Heap *hp)
{
	swap(hp->_data, hp->_data + hp->_size - 1);
	hp->_size--;
	DownAdjust(hp, 0);
}

HPDataType HeapTop(Heap *hp)
{
	if (hp->_size == 0)
	{
		return (HPDataType)0;
	}
	return hp->_data[0];
}

int HeapSize(Heap *hp)
{
	return hp->_size;
}

int HeapEmpty(Heap *hp)
{
	return hp->_size == 0;
}

void HeapPrint(Heap *hp)
{
	int i;
	int tag = 0;
	int tmp = 1;
	for (i = 0; i < hp->_size; i++)
	{
		printf("%d ", hp->_data[i]);
		if (i == tag)
		{
			putchar('\n');
			tmp *= 2;
			tag += tmp;
		}
	}
}

void HeapSort(Heap *hp)
{
	int tmp = hp->_size;

	while (hp->_size >= 1)
	{
		HeapPop(hp);
	}

	hp->_size = tmp;
}