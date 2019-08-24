#ifndef _QUEUE_H_
#define _QUEUE_H_

typedef int QuDataType;

typedef struct QueueNode
{
	QuDataType _data;
	struct QueueNode* _next;
}QueueNode;

typedef struct Queue {
	QueueNode * _head;
	QueueNode * _rear;
}Queue;

void QueueInit(Queue* plist);
void QueueDestory(Queue* plist);

void QueuePop(Queue* plist);
void QueuePush(Queue* plist, QuDataType x);
QuDataType QueueTop(Queue* plist);

int QueueIsEmpty(Queue* plist);

#endif //_QUEUE_H_