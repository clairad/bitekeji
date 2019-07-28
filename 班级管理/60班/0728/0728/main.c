#include "Heap.h"
#include <stdio.h>

#define ARRSIZE(a) (sizeof(a) / sizeof(a[0]))

int main()
{
	int a[] = { 1, 6, 3, 7, 9, 8 };

	Heap hp;

	HeapInit(&hp, a, ARRSIZE(a));

	/*HeapPop(&hp);
	HeapPush(&hp, 5);
	HeapPrint(&hp);

	putchar('\n');
	HeapPush(&hp, 10);
	HeapPrint(&hp);*/

	HeapSort(&hp);
	//HeapPrint(&hp);

	memcpy(a, hp._data, ARRSIZE(a) * sizeof(HPDataType));
	int i;
	for (i = 0; i < ARRSIZE(a); i++)
	{
		printf("%d ", a[i]);
	}
	putchar('\n');

	HeapDestory(&hp);
	return 0;
}