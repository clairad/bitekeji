#include <stdio.h>

int fib(int n)
{
	if (n <= 2)
	{
		return 1;
	}
	return fib(n - 1) + fib(n - 2);
}

int fibN(int n)
{
	int an, an_1 = 1, an_2 = 1;
	int i;

	if (n < 2)
	{
		return 1;
	}

	for (i = 2; i < n; i++)
	{
		an = an_1 + an_2;
		an_2 = an_1;
		an_1 = an;
	}
	return an;
}

int main()
{
	printf("%d\n", fibN(8));
	printf("%d\n", fib(6));

	system("pause");
	return 0;
}