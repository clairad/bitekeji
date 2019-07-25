#include "queue.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void QueueInit(Queue* pq)
{
	pq->front = NULL;
	pq->rear = NULL;
}

void QueueDestory(Queue* pq)
{
	if (pq->front == NULL)
	{
		return;
	}

	while (pq->front)
	{
		QueuePop(pq);
	}
}

QueueNode * BuyQueueNode(QuDataType x)
{
	QueueNode * cur = (QueueNode *)malloc(sizeof(QueueNode));
	cur->data = x;
	cur->next = NULL;
	return cur;
}

void QueuePop(Queue* pq)
{
	if (pq->front == NULL)
	{
		return;
	}
	QueueNode* tmp = pq->front->next;
	free(pq->front);
	pq->front = tmp;
}

void QueuePush(Queue* pq, QuDataType x)
{
	QueueNode * cur = BuyQueueNode(x);

	if (pq->front == NULL)
	{
		pq->front = pq->rear = cur;
	}
	else
	{
		pq->rear->next = cur;
		pq->rear = cur;
	}
}

QuDataType QueueFront(Queue* pq)
{
	return pq->front->data;
}

int QueueIsEmpty(Queue* pq)
{
	return pq->front == NULL;
}