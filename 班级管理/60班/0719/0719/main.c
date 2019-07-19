#include <stdio.h>
#include "List.h"

int main()
{
	List list;

	ListInit(&list);

	ListPushBack(&list, 5);
	ListPushBack(&list, 8);
	ListPushBack(&list, 9);
	ListPushFront(&list, 2);
	ListPushFront(&list, 1);

	ListPopFront(&list, 1);
	ListPopBack(&list, 5);

	ListRemove(&list, 8);
	ListPrint(&list);

	ListDestory(&list);
	return 0;
}