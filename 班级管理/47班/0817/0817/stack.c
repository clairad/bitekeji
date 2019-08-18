#include "stack.h"

void StackInit(Stack* psl, size_t capicity)
{
	assert(psl);

	psl->capicity = capicity;
	psl->array = (StDataType *)malloc(capicity * sizeof(StDataType));
	assert(psl->array);

	psl->size = 0;
}

void StackDestory(Stack* psl)
{
	assert(psl);

	if (psl->array)
	{
		free(psl->array);
		psl->array = NULL;
		psl->size = 0;
		psl->capicity = 0;
	}
}

void CheckCapacity(Stack* psl)
{
	assert(psl);

	if (psl->size == psl->capicity)
	{
		psl->capicity *= 2;
		psl->array = (StDataType *)realloc(psl->array, psl->capicity * sizeof(StDataType));
	}
}

void StackPush(Stack* psl, StDataType x)
{
	assert(psl);

	CheckCapacity(psl);

	psl->array[psl->size] = x;
	psl->size++;
}

void StackPop(Stack* psl)
{
	assert(psl || psl->size);

	psl->size--;
}

StDataType StackTop(Stack* psl)
{
	if (StackIsEmpty(psl))
	{
		return (StDataType)0;
	}
	return psl->array[psl->size - 1];
}

int StackIsEmpty(Stack* psl)
{
	return psl->size == 0;
}