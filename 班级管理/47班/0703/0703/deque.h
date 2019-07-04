#ifndef _deque_H_
#define _deque_H_

#include <stdio.h>
#include <stdlib.h>
#define QUEUENUM 5
typedef int DataType;

typedef struct{
	DataType _data[QUEUENUM];
	DataType * _head;
	DataType * _tail;
	size_t _size;
}deque;

void dequeInit(deque * qu);
void dequeEmpty(deque * qu);
int dequePush(deque * qu, DataType x);
size_t dequeSize(deque * qu);


#endif //_deque_H_