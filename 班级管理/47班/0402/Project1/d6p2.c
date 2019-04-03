#include <stdio.h>

void swapArgs(int *pa, int *pb)
{
	int tmp;
	tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}

int main62()
{
	int a = 3, b = 5;
	swapArgs(&a, &b);
	printf("a = %d, b = %d\n", a, b);
	system("pause");
	return 0;
}