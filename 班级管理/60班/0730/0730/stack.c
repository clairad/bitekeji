#include "stack.h"

void StackInit(Stack* psl, size_t capacity)
{
	psl->array = (STDataType *)calloc(capacity, sizeof(STDataType));
	psl->capacity = capacity;
	psl->size = 0;
}

void StackDestory(Stack* psl)
{
	if (psl->array)
	{ 
		free(psl->array);
		psl->array = NULL;
		psl->size = 0;
		psl->capacity = 0;
	}
}

void CheckCapacity(Stack* psl)
{
	if (psl->size >= psl->capacity)
	{
		psl->capacity *= 2;
		psl->array = (STDataType *)realloc(psl->array, psl->capacity * sizeof(STDataType));
	}
}

void StackPush(Stack* psl, STDataType x)
{
	CheckCapacity(psl);

	psl->array[psl->size] = x;
	psl->size++;
}

void StackPop(Stack* psl)
{
	if (psl->size == 0)
	{
		return;
	}
	psl->size--;
}

STDataType StackFront(Stack* psl)
{
	if (psl->size == 0)
	{
		return (STDataType)0;
	}
	return psl->array[psl->size - 1];
}

int StackIsEmpty(Stack* pq)
{
	return pq->size == 0;
}