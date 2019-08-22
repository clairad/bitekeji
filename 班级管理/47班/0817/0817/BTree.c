#include "BTree.h"
#include "queue.h"
#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

static int s_n;

BTNode *BinaryTreeCreateExe(BTDataType * src)
{
	if (src[s_n] == '#')
	{
		s_n++;
		return NULL;
	}

	BTNode * cur = (BTNode *)malloc(sizeof(BTNode));
	cur->data = src[s_n];
	s_n++;

	cur->lchild = BinaryTreeCreateExe(src);
	cur->rchild = BinaryTreeCreateExe(src);

	return cur;
}

BTNode *BinaryTreeCreate(BTDataType * src)
{
	s_n = 0;
	return BinaryTreeCreateExe(src);
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
	BTNode * cur = root; //从根开始

	StackInit(&st, 100);

	while (cur)
	{ 
		putchar(cur->data); //访问当前节点

		if (cur->rchild) //如果有右孩子，右孩子入栈
		{
			StackPush(&st, cur->rchild);
		}

		if (cur->lchild) //如果有左孩子，访问左孩子
		{
			cur = cur->lchild;
		}
		else //没有左孩子就取栈顶
		{
			cur = StackTop(&st); //取到空时，遍历结束，循环跳出
			StackPop(&st);
		}
	}
	StackDestory(&st);
}


void BinaryTreeInOrderNonR(BTNode * root)
{
	BTNode * cur = root;

	Stack st;
	StackInit(&st, 100);

	while (cur || !StackIsEmpty(&st))
	{
		for (; cur; cur = cur->lchild) //将当前节点及左孩子们入栈
		{
			StackPush(&st, cur);
		}

		cur = StackTop(&st); 
		//1、如果右孩子为空，for循环不进，直接取栈顶
		//2、如果有孩子不为空，那么这是一个没有左孩子的节点
		//第一种情况是左子树访问完毕，第二种情况是左子树为空，无论哪种，当前节点都要打印
		putchar(cur->data);
		StackPop(&st);
		cur = cur->rchild; //当右子树为空时，检查栈是否为空，如果栈也空了，循环跳出
	}

	StackDestory(&st);
}

void BinaryTreePostOrderNonR(BTNode* root)
{
	char tag[64];

	BTNode * cur = root;

	Stack st;
	StackInit(&st, 100);

	do{
		for (; cur; cur = cur->lchild) //类似中序，将当前节点及其左孩子们入栈
		{
			StackPush(&st, cur);
			tag[st.size - 1] = 0; //重置左子树访问标记（LT）
		}

		while (!StackIsEmpty(&st) && tag[st.size - 1]) 
		//前面的条件只在最后一次循环跳出的时候生效
		//后面的条件分两个情况：
		//1、当cur的为空时，上面的for不进，此条件成立
		//2、当cur不为空，上面的for进，则此条件不成立
		//如果检测到当前的LT被置位（也就是情况1），那么在打印完当前节点后，再去直接检查上一个节点（父节点）是不是也要被打印了（LT置位，证明这是它的右子树，它也要被打印了），所以要用while循环打印
		{
			cur = StackTop(&st);
			putchar(cur->data);
			StackPop(&st);
		}

		if (!StackIsEmpty(&st)) //此条件只在最后一次循环跳出时生效
		{ 
			cur = StackTop(&st);
			//1、如果上面的while进了，那么证明左子树访问完毕了，给LT置位
			//2、如果上面的while没进，那么证明左子树不存在，给LT置位
			tag[st.size - 1] = 1;
			cur = cur->rchild;
			//左子树访问完毕后，访问右子树
		}
	} while (!StackIsEmpty(&st));
	//由于后序遍历中根节点是最后出栈的，所以在根节点出栈前，栈不可能为空，所以以栈是否为空来判定是否要跳出

	StackDestory(&st);
}

int BinaryTreeComplete(BTNode* root)
{
	Queue qu;
	BTNode * cur;
	int tag = 0;

	QueueInit(&qu);

	QueuePush(&qu, root);

	while (!QueueIsEmpty(&qu))
	{
		cur = QueueTop(&qu);

		putchar(cur->data);

		if (cur->rchild && !cur->lchild)
		{
			return 0;
		}

		if (tag && (cur->rchild || cur->lchild))
		{
			return 0;
		}

		if (cur->lchild)
		{
			QueuePush(&qu, cur->lchild);
		}

		if (cur->rchild)
		{
			QueuePush(&qu, cur->rchild);
		}
		else
		{
			tag = 1;
		}

		QueuePop(&qu);
	}

	QueueDestory(&qu);
	return 1;
}
