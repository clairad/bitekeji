#include <stdio.h>

void swapArgs(int * pi, int * pj)
{
	int tmp;

	tmp = *pi;
	*pi = *pj;
	*pj = tmp;
}

int main62()
{
	int i = 4, j = 7;

	swapArgs(&i, &j);
	printf("i = %d, j = %d\n", i, j);
	return 0;
}