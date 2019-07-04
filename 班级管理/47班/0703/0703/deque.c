#include "deque.h"


void dequeInit(deque * qu)
{
	qu->_head = qu->_tail = qu->_data;
	qu->_size = 0;
}

void dequeEmpty(deque * qu)
{
	qu->_head = qu->_tail;
	qu->_size = 0;
}

int dequePush(deque * qu, DataType x)
{
	*qu->_tail = x;
	if (qu->_tail + 1 == qu->_head ||
		(qu->_tail + 1 - qu->_data == QUEUENUM &&
		qu->_head == qu->_data))
	{
		return -1;
	}
	qu->_tail++;
	if (qu->_tail - qu->_data == QUEUENUM)
	{
		qu->_tail = qu->_data;
	}
	qu->_size++;
	return 0;
}

void dequePop(deque * qu)
{
	qu->_head++;
	if (qu->_head - qu->_data == QUEUENUM)
	{
		qu->_head = qu->_data;
	}
	qu->_size--;
}

DataType dequeFront(deque * qu)
{
	return *qu->_head;
}

/*
DataType dequeBack(deque * qu)
{
	if (qu->_tail == qu->_data)
	{
		return qu->_data[QUEUENUM - 1];
	}
	return qu->_tail[-1];
}
*/

int dequeIsEmpty(deque * qu)
{
	return qu->_head == qu->_tail;
}

size_t dequeSize(deque * qu)
{
	return qu->_size;
}