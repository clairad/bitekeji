#include <stdio.h>

int add(int a, int b)
{
	return a + b;
}

int main()
{
	
	int (*pfunc)(int, int) = add;
	
	printf("%d", pfunc(1, 2));
	return 0;
}
