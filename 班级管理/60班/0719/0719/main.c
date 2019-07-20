#include <stdio.h>
#include "List.h"

int main()
{
	List list;

	ListInit(&list);

	ListPushBack(&list, 5);
	ListPushBack(&list, 5);
	ListPushBack(&list, 5);
	ListPushBack(&list, 6);
	ListPushBack(&list, 7);
	ListPushBack(&list, 7);
	ListPushFront(&list, 2);
	ListPushFront(&list, 2);
	ListPushFront(&list, 2);
	ListPushFront(&list, 1);

	ListDistinct(&list);

	List list2;

	ListInit(&list2);

	ListPushBack(&list2, 3);
	ListPushBack(&list2, 4);
	ListPushBack(&list2, 8);
	ListPushBack(&list2, 9);
	ListPushBack(&list2, 10);

	ListMerge(&list, &list2);
	//ListPopFront(&list, 1);
	//ListPopBack(&list, 5);

	//ListRemove(&list, 8);
	ListPrint(&list);

	ListDestory(&list);
	return 0;
}