#include <stdio.h>

void p(int i)
{
	printf("%d\n", i);
}

void(*signal(int i, void(*p)(int)))(int)
{
	p(i);
	return p;
}

int main2()
{
	signal(3, p)(5);
	return 0;
}

int add(int a, int b)
{
	return a + b;
}

int sub(int a, int b)
{
	return a - b;
}

int mul(int a, int b)
{
	return a * b;
}

int div(int a, int b)
{
	return a / b;
}

int main()
{
	int(*pfunc[6])(int, int) = {
		mul, add, NULL, sub, NULL, div
	};
	int a, b;
	char c;
	scanf("%d%c%d", &a, &c, &b);
	printf("%d", pfunc[c - '*'](a, b));
	return 0;
}