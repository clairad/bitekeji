#include "BTree.h"
#include "queue.h"
#include "stack.h"
#include <stdlib.h>

BTNode* BinaryTreeCreate(BTDataType* a)
{
	BTNode * cur;
	static int i = 0;
	
	if (a[i] == ENDTAG)
	{
		i++;
		return NULL;
	}
	cur = (BTNode *)malloc(sizeof(BTNode));
	cur->_data = a[i];
	i++;
	cur->_left = BinaryTreeCreate(a);
	cur->_right = BinaryTreeCreate(a);

	return cur;
}

void BinaryTreePrevOrder(BTNode* root)
{
	if (root != NULL)
	{
		printf("%c", root->_data);
		BinaryTreePrevOrder(root->_left);
		BinaryTreePrevOrder(root->_right);
	}
}

void BinaryTreeInOrder(BTNode* root)
{
	if (root != NULL)
	{
		BinaryTreeInOrder(root->_left);
		printf("%c", root->_data);
		BinaryTreeInOrder(root->_right);
	}
}

void BinaryTreePostOrder(BTNode* root)
{
	if (root != NULL)
	{
		BinaryTreePostOrder(root->_left);
		BinaryTreePostOrder(root->_right);
		printf("%c", root->_data);
	}
}

void BinaryTreeLevelOrder(BTNode* root)
{
	Queue qu;
	BTNode * tmp;

	QueueInit(&qu);

	QueuePush(&qu, root);
	while (!QueueIsEmpty(&qu))
	{
		tmp = QueueFront(&qu);
		printf("%c", tmp->_data);
		if (tmp->_left)
		{
			QueuePush(&qu, tmp->_left);
		}
		if (tmp->_right)
		{
			QueuePush(&qu, tmp->_right);
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

	while (cur || !StackIsEmpty(&st))
	{
		putchar(cur->_data);

		if (cur->_right)
		{
			StackPush(&st, cur->_right);
		}

		if (cur->_left)
		{
			cur = cur->_left;
		}
		else
		{
			cur = StackFront(&st);
			StackPop(&st);
		}
	}
	StackDestory(&st);
}

void BinaryTreeInOrderNonR(BTNode* root)
{
	Stack st;
	BTNode * cur = root;

	StackInit(&st, 100);

	while (1)
	{
		for (; cur; cur = cur->_left)
		{
			StackPush(&st, cur);
		}

		while (1)
		{ 
			cur = StackFront(&st);
			putchar(cur->_data);
			StackPop(&st);

			if (cur->_right)
			{
				cur = cur->_right;
				break;
			}

			if (StackIsEmpty(&st))
			{
				StackDestory(&st);
				return;
			}
		}
	}
}

int SeqFind(BTNode * src[], size_t size, BTNode * f)
{
	int i;
	for (i = 0; i < size; i++)
	{
		if (src[i] == f)
		{
			return 1;
		}
	}
	return 0;
}

void BinaryTreePostOrderNonR(BTNode* root)
{
	Stack st;
	BTNode * cur = root;
	BTNode * tmp = NULL;
	BTNode * visited[20];
	BTNode * printed[20];
	size_t size = 0, sizep = 0;
	int flag = 0;

	StackInit(&st, 100);

	StackPush(&st, root);
	while (cur || !StackIsEmpty(&st))
	{
		if (cur->_right)
		{
			if (!SeqFind(visited, size, cur->_right))
			{ 
				StackPush(&st, cur->_right);
				visited[size] = cur->_right;
				size++;
			}
		}
		
		if (cur->_left)
		{
			if (!SeqFind(visited, size, cur->_left))
			{
				StackPush(&st, cur->_left);
				visited[size] = cur->_left;
				size++;
				cur = cur->_left;
			}
		}
		else
		{
			if (!SeqFind(printed, sizep, cur->_right))
			{
				cur = cur->_right;
			}
		}

		if ((cur->_left == NULL || SeqFind(visited, size, cur->_left)) && 
			(cur->_right == NULL || SeqFind(visited, size, cur->_right)))
		{
			putchar(cur->_data);
			StackPop(&st);
			printed[sizep] = cur;
			sizep++;
			cur = StackFront(&st);
		}

	}

	StackDestory(&st);
}