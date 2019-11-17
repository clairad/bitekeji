#include <stdio.h>

/*
改过了就是出参，用过了就是入参

拿去用用传本身，帮我改改传地址
*/

void swap(int *pa, int *pb)
{
	int tmp;

	tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}
/*
void swap(int *pa, int *pb)
{
	int * tmp;

	tmp = pa;
	pa = pb;
	pb = tmp;
}
*/
int d7p2()
{
	int a = 5, b = 8;

	swap(&a, &b);

	printf("%d %d", a, b);
	return 0;
}