#include "SList.h"
#include <stdio.h>

int main()
{
	SListNode *phead;

	SListInit(&phead);

	SListPushFront(&phead, 1);
	SListPushFront(&phead, 2);
	SListPushFront(&phead, 3);
	SListPushFront(&phead, 4);
	SListPushFront(&phead, 5);
	SListPushFront(&phead, 6);
	SListPushFront(&phead, 7);
	SListPushFront(&phead, 8);
	SListPushFront(&phead, 9);
	//SListPopFront(&phead);
	//SListPopFront(&phead);
	/*
	SListInsertAfter(SListFind(phead, 6), 9);
	SListEraseAfter(SListFind(phead, 4));

	SListRemove(&phead, 7);
	SListPrint(phead);
	*/
	//SListRemoveAll(&phead, 8);
	SListReverse2(&phead);
	SListPrint(phead);


	SListDestory(&phead);
	
	//SListPrint(phead);
	return 0;
}

int _main()
{
	SListNode *phead;
	SListNode *plast;
	SListNode *cur;
	int m = 6, n = 5;
	int i;
	SListInit(&phead);

	SListPushFront(&phead, m);
	plast = phead;
	for (i = m - 1; i >= 1; i--)
	{
		SListPushFront(&phead, i);
	}
	plast->next = phead;

	cur = plast;
	for (; m > 1; m--)
	{
		for (i = 1; i < n; i++)
		{
			cur = cur->next;
		}
		SListEraseAfter(cur);
	}

	printf("%d", cur->data);

	free(cur);
	return 0;
}