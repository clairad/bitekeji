#include "queue.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void QueueInit(Queue* plist)
{
	assert(plist);
	plist->_head = NULL;
	plist->_rear = NULL;
}

void QueueDestory(Queue* plist)
{
	QueueNode * tmp;
	while (plist->_head)
	{ 
		tmp = plist->_head;
		plist->_head = plist->_head->_next;
		free(tmp);
	}
}

void QueuePop(Queue* plist)
{
	assert(plist);

	QueueNode * tmp;
	if (plist->_head)
	{ 
		tmp = plist->_head;
		plist->_head = plist->_head->_next;
		free(tmp);
	}
}

void QueuePush(Queue* plist, QuDataType x)
{
	QueueNode * cur = (QueueNode *)malloc(sizeof(QueueNode));
	cur->_data = x;
	cur->_next = NULL;

	if (QueueIsEmpty(plist))
	{
		plist->_head = plist->_rear = cur;
		return;
	}

	plist->_rear->_next = cur;
	plist->_rear = cur;
}

int QueueIsEmpty(Queue* plist)
{
	return plist->_head == NULL;
}

QuDataType QueueTop(Queue* plist)
{
	if (QueueIsEmpty(plist))
	{
		return (QuDataType)0;
	}
	return plist->_head->_data;
}