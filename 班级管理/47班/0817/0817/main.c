#include "BTree.h"
#include "queue.h"
#include "stack.h"

int main()
{
	BTNode * root = BinaryTreeCreate("ABD#GI##J###CE#HK###F##");
	
	BinaryTreePrevOrder(root);
	putchar('\n');
	BinaryTreeInOrder(root);
	putchar('\n');
	BinaryTreePostOrder(root);
	putchar('\n');

	BinaryTreeLevelOrder(root);
	putchar('\n');

	BinaryTreePrevOrderNonR(root);
	putchar('\n');

	BinaryTreeDestory(root);
	return 0;
}
/*
void stacktest()
{
	Stack st;

	StackInit(&st, 100);

	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	printf("%d ", StackTop(&st));
	StackPop(&st);
	StackPush(&st, 4);
	StackPush(&st, 5);

	printf("%d ", StackTop(&st));
	StackPop(&st);
	printf("%d ", StackTop(&st));
	StackPop(&st);
	printf("%d ", StackTop(&st));
	StackPop(&st);
	printf("%d ", StackTop(&st));
	StackPop(&st);

	StackDestory(&st);
}


void queuetest()
{
	Queue qu;

	QueueInit(&qu);

	QueuePush(&qu, 1);
	QueuePush(&qu, 2);
	QueuePush(&qu, 3);
	printf("%d ", QueueTop(&qu));
	QueuePop(&qu);
	printf("%d ", QueueTop(&qu));
	QueuePop(&qu);
	QueuePush(&qu, 4);
	QueuePush(&qu, 5);
	printf("%d ", QueueTop(&qu));
	QueuePop(&qu);
	printf("%d ", QueueTop(&qu));
	QueuePop(&qu);
	QueuePush(&qu, 6);

	printf("%d ", QueueTop(&qu));
	QueuePop(&qu);
	printf("%d ", QueueTop(&qu));
	QueuePop(&qu);

	QueuePop(&qu);
	QueuePush(&qu, 6);

	printf("%d ", QueueTop(&qu));
	QueuePop(&qu);

	QueueDestory(&qu);
}
*/