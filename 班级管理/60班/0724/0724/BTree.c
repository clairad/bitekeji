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

void BinaryTreeDestory(BTNode* root)
{
	BTNode *left, *right;

	if (root)
	{
		left = root->_left;
		right = root->_right;
		free(root);
		BinaryTreeDestory(left);
		BinaryTreeDestory(right);
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
	BTNode * cur = root;

	Stack st;
	StackInit(&st, 100);

	while (cur || !StackIsEmpty(&st)) //当cur为空且栈为空时，循环跳出，代表树遍历完毕
	{
		for (; cur; cur = cur->_left) 
		//1、把目前的根及其所有的左孩子压栈，直到找不到左孩子为止
		//2、以目前的右孩子作为根，继续将他的左孩子们压栈
		{
			StackPush(&st, cur);
		}

		if (!StackIsEmpty(&st))
		{
			cur = StackFront(&st); 
			//1、左孩子遍历完毕后，第一个没有左孩子的节点就是中序的第一个输出
			//2、如果右孩子为空，此时栈里将会是下一个要访问的节点
			//   如果有右孩子，那么此时栈里将会是以那个右孩子为跟的子树中第一个没有左孩子的节点
			putchar(cur->_data); 
			//1、由于没有左孩子了，所以打印根
			StackPop(&st);
			cur = cur->_right; 
			//1、左子树和根遍历结束后，遍历它的右子树
		}
	}
	StackDestory(&st);
}


void BinaryTreePostOrderNonR(BTNode* root)
{
	BTNode * cur = root;

	Stack st;
	int tag[32] = { 0 }; //左孩子遍历标签

	StackInit(&st, 100);

	while (cur || !StackIsEmpty(&st))
	{
		for (; cur; cur = cur->_left) //类似中序，将左孩子入栈，cur为空时，代表上一个节点的右孩子为空，只有这种情况，才可能进入下面的while
		{
			StackPush(&st, cur); //push操作会导致size+1
			tag[st.size] = 0; //由于入栈的是左孩子，所以这里的左孩子遍历标签置0
		}

		//只要上面的for执行过哪怕一次循环（右孩子不为空），这个while的后半部分条件都不可能满足
		while (!StackIsEmpty(&st) && tag[st.size] == 1) //左孩子还没遍历完成时，不能进入打印
		//所以，这里确保了只有左右子树都遍历完成时，才会进入这个while
		{
			cur = StackFront(&st);
			putchar(cur->_data); //打印根
			StackPop(&st); //pop操作会导致size-1
			cur = NULL; //为了循环正常跳出
		}

		if (!StackIsEmpty(&st))
		{
			tag[st.size] = 1; //进入这里证明左子树遍历完毕，左子树标签置1
			cur = StackFront(&st)->_right; //进入右子树继续遍历
		}
	}
	StackDestory(&st);
}

int BinaryTreeComplete(BTNode* root)
{
	Queue qu;
	BTNode * tmp;
	int leafflag = 0;

	QueueInit(&qu);

	QueuePush(&qu, root);
	while (!QueueIsEmpty(&qu))
	{
		tmp = QueueFront(&qu);
		printf("%c", tmp->_data);

		QueuePop(&qu);
		if (leafflag)
		{
			if (tmp->_left || tmp->_right)
			{ 
				return 0;
			}
			continue;
		}

		if (tmp->_left && tmp->_right)
		{
			QueuePush(&qu, tmp->_left);
			QueuePush(&qu, tmp->_right);
		}
		else if (tmp->_right && !tmp->_left)
		{
			return 0;
		}
		else
		{
			leafflag = 1;
			if (tmp->_left)
			{
				QueuePush(&qu, tmp->_left);
			}
		}
	}
	QueueDestory(&qu);
	return 1;
}

/*
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
*/

