#include "seqList.h"
#include "slist.h"

void SListInsertFront(SList* plist, SLTDataType x);

void listtest()
{
	SList test;

	SListInit(&test);
	SListPushFront(&test, 1);
	SListPushFront(&test, 2);
	SListPushFront(&test, 4);
	SListPushFront(&test, 6);
	SListPushFront(&test, 9);

	SListPrint(&test);

	SListPopFront(&test);
	SListPrint(&test);

	SListInsertAfter(SListFind(&test, 4), 8);
	SListPrint(&test);

	SListEraseAfter(SListFind(&test, 8));

	SListInsertFront(&test, 6, 10);
	SListPrint(&test);
	SListDestory(&test);
}

void seqtest()
{
	SeqList test;

	SeqListInit(&test, 10);

	SeqListPushBack(&test, 1);
	SeqListPushBack(&test, 2);
	SeqListPushBack(&test, 3);
	SeqListPushBack(&test, 4);
	SeqListPushBack(&test, 5);
	SeqListPushBack(&test, 6);
	SeqListPushBack(&test, 7);
	SeqListPushBack(&test, 8);
	SeqListPushBack(&test, 9);
	SeqListPushFront(&test, 10);
	SeqListPushFront(&test, 10);
	SeqListPushFront(&test, 10);


	SeqListPopBack(&test);
	SeqListPopBack(&test);
	SeqListPopBack(&test);
	SeqListPopBack(&test);
	SeqListPopFront(&test);
	
	SeqListInsert(&test, 1, 16);
	SeqListErase(&test, 2);
	SeqListRemove(&test, 4);
	SeqListModify(&test, 5, 6);

	SeqListBubbleSort(&test);
	printf("%d\n", SeqListBinaryFind(&test, 6));

	SeqListPrint(&test);
	SeqListDestory(&test);
}


int main()
{
	listtest();
	return 0;
}