#include <stdio.h>

int sum;
int countnum(int n)
{
	sum++;
	if (n == 1)
	{
		return sum;
	}

	int i;
	for (i = 1; i <= n / 2; i++)
	{
		countnum(i);
	}
	return sum;
}

int ex1()
{
	int n = 1000;

	int i;
	for (i = 1; i < 50; i++)
	{ 
		printf("%d %d\n", i, countnum(i));
		sum = 0;
	}
	return 0;
}