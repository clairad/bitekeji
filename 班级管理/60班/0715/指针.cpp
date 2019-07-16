#include <stdio.h>

int func(int ***pppa, int **ppb)
{
	*pppa = ppb;
}

int main()
{
	int a = 5, b = 10;
	int *pa = &a, *pb = &b;
	int **ppa = &pa, **ppb = &pb;
	
	func(&ppa, ppb);
	
	printf("%d\n", **ppa);
	printf("%d\n", *pa);
	return 0;
} 
