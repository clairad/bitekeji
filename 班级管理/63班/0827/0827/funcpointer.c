#include <stdio.h>

int add(int a, int b)
{
	return a + b;
}

int main0()
{
	int(*pfunc)(int, int) = add;

	printf("%d", pfunc(2, 3));
	return 0;
}