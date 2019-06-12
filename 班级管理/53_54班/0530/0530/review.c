#include <stdio.h>

struct list{
	int data;
	struct list * next;
};



void func(int ***pppa, int **ppb)
{
	**pppa = *ppb;
}

int main()
{
	


	int a = 3, b = 4;
	int *pa = &a, *pb = &b;
	int **ppa = &pa, **ppb = &pb;

	func(&ppa, ppb);

	printf("%d", **ppa);
	return 0;
}