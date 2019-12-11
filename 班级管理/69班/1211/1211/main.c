#include <stdio.h>

#define s_32 int

typedef int i;

typedef struct {
	int a;
	char b;
}tmp;

typedef int arr5[5];

//#define PINT int *
typedef int * PINT;

int test()
{
	arr5 s;

	printf("%d", sizeof(s));

	int *pa, *pb, a, b, **ppa;

	pa = &a;
	pb = &b;
	ppa = &pa;

	//PINT pa, pb;

	return 0;
}