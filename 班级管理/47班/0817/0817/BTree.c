#include "BTree.h"
#include "queue.h"
#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

BTNode *BinaryTreeCreate(BTDataType * src)
{
	static int s_n = 0;
	if (src[s_n] == '#')
	{
		s_n++;
		return NULL;
	}

	BTNode * cur = (BTNode *)malloc(sizeof(BTNode));
	cur->data = src[s_n];
	s_n++;

	cur->lchild = BinaryTreeCreate(src);
	cur->rchild = BinaryTreeCreate(src);

	return cur;
}

void BinaryTreePrevOrder(BTNode* root)
{
	if (root)
	{ 
		putchar(root->data);
		BinaryTreePrevOrder(root->lchild);
		BinaryTreePrevOrder(root->rchild);
	}
}

void BinaryTreeInOrder(BTNode* root)
{
	if (root)
	{
		BinaryTreeInOrder(root->lchild);
		putchar(root->data);
		BinaryTreeInOrder(root->rchild);
	}
}

void BinaryTreePostOrder(BTNode* root)
{
	if (root)
	{
		BinaryTreePostOrder(root->lchild);
		BinaryTreePostOrder(root->rchild);
		putchar(root->data);
	}
}

void BinaryTreeDestory(BTNode* root)
{
	if (root)
	{
		BinaryTreeDestory(root->lchild);
		BinaryTreeDestory(root->rchild);
		free(root);
	}
}

void BinaryTreeLevelOrder(BTNode* root)
{
	Queue qu;
	BTNode * cur;

	QueueInit(&qu);

	QueuePush(&qu, root);

	while (!QueueIsEmpty(&qu))
	{
		cur = QueueTop(&qu);

		putchar(cur->data);

		if (cur->lchild)
		{
			QueuePush(&qu, cur->lchild);
		}

		if (cur->rchild)
		{
			QueuePush(&qu, cur->rchild);
		}

		QueuePop(&qu);
	}

	QueueDestory(&qu);
}

void BinaryTreePrevOrderNonR(BTNode* root)
{
	Stack st;
	BTNode * cur = root;

	StackInit(&st, 100);

	while (cur)
	{ 
		putchar(cur->data);

		if (cur->rchild)
		{
			StackPush(&st, cur->rchild);
		}

		if (cur->lchild)
		{
			cur = cur->lchild;
		}
		else
		{
			cur = StackTop(&st);
			StackPop(&st);
		}
	}
	StackDestory(&st);
}