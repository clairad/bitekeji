#ifndef _HEAP_H_
#define _HEAP_H_

#define MAXSIZE 100
typedef int HPDataType;

typedef struct Heap {
	HPDataType *_data;
	int _size;
	int _capacity;
}Heap;

void HeapInit(Heap *hp, HPDataType *a, int n);
void HeapDestory(Heap *hp);
void HeapPush(Heap *hp, HPDataType x);
void HeapPop(Heap *hp);
HPDataType HeapTop(Heap *hp);
int HeapSize(Heap *hp);
int HeapEmpty(Heap *hp);

void HeapPrint(Heap *hp);

// ∂—≈≈–Ú
void HeapSort(Heap *hp);

#endif /*_HEAP_H_*/