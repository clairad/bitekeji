#include <stdio.h>

int fib1(int n)
{
	int an, an_1 = 1, an_2 = 1, i;

	if (n <= 2)
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

int fib2(int n)
{
	if (n <= 2)
	{
		return 1;
	}
	return fib2(n - 1) + fib2(n - 2);
}

int main71()
{
	printf("%d\n", fib2(6));


	system("pause");
	return 0;
}