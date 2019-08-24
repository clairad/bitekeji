#include <stdio.h> 

typedef void (*PFUNC)(int);

void func(int a)
{
	printf("%d\n", a);
}

PFUNC signal(int a, PFUNC p)
{
	p(a);
	return p;
}

int add(int a, int b)
{
	return a + b;
}

int main()
{
	//signal(1, func)(2);
	int (*pfunc)(int, int) = add;
	
	printf("%d", pfunc(2, 3));
	return 0;
}

