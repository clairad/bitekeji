#include "seqlist.h"

void SeqListInit(SeqList* psl, size_t capacity)
{
	psl->array = (SLDataType *)calloc(capacity, sizeof(SLDataType));
	psl->capacity = capacity;
	psl->size = 0;
}

void SeqListDestory(SeqList* psl)
{
	if (psl->array)
	{ 
		free(psl->array);
		psl->array = NULL;
		psl->size = 0;
		psl->capacity = 0;
	}
}

void CheckCapacity(SeqList* psl)
{
	if (psl->size >= psl->capacity)
	{
		psl->capacity *= 2;
		psl->array = (SLDataType *)realloc(psl->array, psl->capacity * sizeof(SLDataType));
	}
}

void SeqListPushBack(SeqList* psl, SLDataType x)
{
	CheckCapacity(psl);

	psl->array[psl->size] = x;
	psl->size++;
}

void SeqListPopBack(SeqList* psl)
{
	psl->size--;
}

void SeqListPushFront(SeqList* psl, SLDataType x)
{
	int i;

	CheckCapacity(psl);

	for (i = psl->size - 1; i >= 0; i--)
	{
		psl->array[i + 1] = psl->array[i];
	}
	psl->array[0] = x;
	psl->size++;
}

void SeqListPopFront(SeqList* psl)
{
	int i;

	for (i = 0; i < psl->size - 1; i++)
	{
		psl->array[i] = psl->array[i + 1];
	}
	psl->size--;
}

int SeqListFind(SeqList* psl, SLDataType x)
{
	int i;

	for (i = 0; i < psl->size; i++)
	{
		if (Contactcmp(*psl->array[i]->_data, *x->_data) == 0)
		{
			return i;
		}
	}
	return -1;
}

void SeqListInsert(SeqList* psl, size_t pos, SLDataType x)
{
	int i;

	CheckCapacity(psl);

	for (i = psl->size - 1; i >= pos; i--)
	{
		psl->array[i + 1] = psl->array[i];
	}
	psl->array[pos] = x;
	psl->size++;
}
void SeqListErase(SeqList* psl, size_t pos)
{
	int i;

	for (i = pos; i < psl->size - 1; i++)
	{
		psl->array[i] = psl->array[i + 1];
	}
	psl->size--;
}

void SeqListRemove(SeqList* psl, SLDataType x)
{
	SeqListErase(psl, SeqListFind(psl, x));
}

void SeqListModify(SeqList* psl, size_t pos, SLDataType x)
{
	psl->array[pos] = x;
}

void SeqListPrint(SeqList* psl)
{
	int i;

	for (i = 0; i < psl->size; i++)
	{
		printData(*psl->array[i]->_data);
	}
	putchar('\n');
}

void SeqListBubbleSort(SeqList* psl)
{
	int i, j;
	SLDataType tmp;

	for (i = 0; i < psl->size - 1; i++)
	{
		for (j = 0; j < psl->size - 1 - i; j++)
		{
			if (Contactcmp(*psl->array[j]->_data, *psl->array[j + 1]->_data) > 0)
			{
				tmp = psl->array[j];
				psl->array[j] = psl->array[j + 1];
				psl->array[j + 1] = tmp;
			}
		}
	}
}

int SeqListBinaryFind(SeqList* psl, SLDataType x)
{
	int start = 0;
	int end = psl->size - 1;
	int mid;

	while (start <= end)
	{
		mid = (start + end) / 2;
		if (Contactcmp(*psl->array[mid]->_data, *x->_data) < 0)
		{
			start = mid + 1;
		}
		else if (Contactcmp(*psl->array[mid]->_data, *x->_data) > 0)
		{
			end = mid - 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}
/*
void SeqListRemoveAll(SeqList* psl, SLDataType x)
{
	int gap = 0;
	int i;
	for (i = 0; i < psl->size - gap; i++)
	{
		if (psl->array[i + gap] == x)
		{
			if (psl->array[i + gap] == psl->array[i + gap + 1])
			{
				i--;
				gap++;
				continue;
			}

			gap++;

			if (i + gap >= psl->capacity)
			{
				break;
			}
		}
		psl->array[i] = psl->array[i + gap];
	}
	psl->size -= gap;
}
*/

void SeqListRemoveAll(SeqList* psl, SLDataType x)
{
	int gap = 0, i;

	for (i = 0; i < psl->size; i++)
	{
		if (Contactcmp(*psl->array[i]->_data, *x->_data) == 0)
		{
			gap++;
		}
		else
		{
			psl->array[i - gap] = psl->array[i];
		}
	}
	psl->size -= gap;
}
/*
void SeqListRemoveAll(SeqList* psl, SLDataType x)
{
	SLDataType * tmp = (SLDataType *)calloc(psl->capacity, sizeof(SLDataType));
	int i, j;

	for (i = 0, j = 0; i < psl->size; i++)
	{
		if (psl->array[i] != x)
		{ 
			tmp[j] = psl->array[i];
			j++;
		}
	}

	free(psl->array);
	psl->array = tmp;
	psl->size = j;
}
*/