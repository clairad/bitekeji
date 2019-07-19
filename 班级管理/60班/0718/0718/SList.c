#include "SList.h"
#include <stdio.h>
#include <math.h>

SListNode* BuySListNode(SLTDataType x)
{
	SListNode* res = (SListNode*)malloc(sizeof(SListNode));
	res->data = x;
	res->next = NULL;
	return res;
}

void SListInit(SListNode** pphead)
{
	*pphead = NULL;
}

void SListDestory(SListNode** pphead)
{
	if (*pphead == NULL)
	{
		return;
	}

	while ((*pphead)->next)
	{
		SListEraseAfter(*pphead);
	}
	free(*pphead);
	*pphead = NULL;
}


void SListPushFront(SListNode** pphead, SLTDataType x)
{
	SListNode* tmp = BuySListNode(x);
	tmp->next = *pphead;
	*pphead = tmp;
}

void SListPopFront(SListNode** pphead)
{
	if (*pphead == NULL)
	{
		return;
	}
	SListNode* tmp = (*pphead)->next;
	free(*pphead);
	*pphead = tmp;
}

SListNode* SListFind(SListNode* phead, SLTDataType x)
{
	SListNode* tmp;
	for (tmp = phead; tmp; tmp = tmp->next)
	{
		if (tmp->data == x)
		{
			return tmp;
		}
	}
	return NULL;
}

void SListInsertAfter(SListNode* pos, SLTDataType x)
{
	SListNode* tmp = BuySListNode(x);
	tmp->next = pos->next;
	pos->next = tmp;
}

void SListEraseAfter(SListNode* pos)
{
	SListNode* tmp = pos->next;
	if (tmp == NULL)
	{
		return;
	}
	pos->next = tmp->next;
	free(tmp);
}


void SListRemoveAll(SListNode** pphead, SLTDataType x)
{
	SListNode* tmp;
	while (*pphead && (*pphead)->data == x)
	{
		SListPopFront(pphead);
	}

	for (tmp = *pphead; tmp && tmp->next; )
	{
		if (tmp->next->data == x)
		{
			SListEraseAfter(tmp);
		}
		else
		{
			tmp = tmp->next;
		}
	}
}

void SListRemove(SListNode** pphead, SLTDataType x)
{
	SListNode* tmp;
	if (*pphead == NULL)
	{
		return;
	}

	if ((*pphead)->data == x)
	{
		SListPopFront(pphead);
		return;
	}

	for (tmp = *pphead; tmp->next; tmp = tmp->next)
	{
		if (tmp->next->data == x)
		{
			SListEraseAfter(tmp);
			return;
		}
	}
}

void SListPrint(SListNode* phead)
{
	SListNode* tmp;
	for (tmp = phead; tmp; tmp = tmp->next)
	{
		printf("%d->", tmp->data);
	}
	printf("NULL\n");
}


void SListReverse(SListNode **pphead)
{
	SListNode *head = *pphead;   //此指针在每次循环中始终指向当前链表的头
	SListNode *tmp = head->next; //此指针在每次循环中始终指向要被后删头插的节点
	SListNode *oldh = *pphead;   //此指针在每次循环中始终指向原本的头结点，不会改变指向

	while (tmp) //如果tmp为空，则代表逆序结束，旧头的next已经是空的了，成为新链表的末尾
	{
		oldh->next = tmp->next; //将tmp架空，实际是后删操作的一部分
		tmp->next = head; //让tmp变成新的头，实际是头插操作的一部分 
		head = tmp; //换头
		tmp = oldh->next; //让tmp变成下次循环中待删除的节点
	}
	*pphead = head;
}

void SListReverse2(SListNode **pphead)
{
	SListNode *pre = *pphead;   //被执行操作的前一个节点
	SListNode *cur = pre->next; //被执行操作的节点
	SListNode *next = cur;      //被执行操作的后一个节点，暂时指在cur，在循环开始的时候跳转到其后一个节点

	pre->next = NULL; //此时的头，将会是转换后的尾，这里是在设置链表尾节点
	while (next)
	{ 
		next = next->next; //先让next变成下一个节点，之所以不放在最后，是因为会有next为空的限制
		cur->next = pre; //让原本指着后面的指到前面来（先后转）
		pre = cur; //为了下次循环而传递数据，这里是设置下次循环的上一个节点（本次执行操作的节点将会成下次循环的上一个节点）
		cur = next; //同上（本次的下一个节点将会成为下次的被执行节点）
	}

	*pphead = pre; //循环跳出后cur和next都已经指向空了，pre才是新的头
}

SListNode *getIntersectionNode(SListNode *headA, SListNode *headB)
{
	int lenA = 0;
	int lenB = 0;
	int gap;
	int i;
	SListNode * cur;
	SListNode * longerlist = headA;
	SListNode * shorterlist = headB;

	for (cur = headA; cur; cur = cur->next)
	{
		lenA++;
	}

	for (cur = headB; cur; cur = cur->next)
	{
		lenB++;
	}

	gap = abs(lenA - lenB);
	if (lenA < lenB)
	{
		longerlist = headB;
		shorterlist = headA;
	}

	for (i = 0; i < gap; i++)
	{
		longerlist = longerlist->next;
	}
	
	for (; longerlist && shorterlist; longerlist = longerlist->next, shorterlist = shorterlist->next)
	{
		if (longerlist == shorterlist)
		{
			return longerlist;
		}
	}
	return NULL;
}

SListNode *detectCycle(SListNode *head)
{
	SListNode * fast = head;
	SListNode * slow = head;

	while (fast && slow && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
		{
			break;
		}
	}

	for (; fast && fast->next; fast = fast->next, head = head->next)
	{
		if (fast == head)
		{
			return fast;
		}
	}
	return NULL;
}
