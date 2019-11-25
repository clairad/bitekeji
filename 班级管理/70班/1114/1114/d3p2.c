#include <stdio.h>

int d3p2()
{
	int i;
	double sum = 0;
	double tmp = 1;
	int flag = 1;
	for (i = 1; i <= 100; i++)
	{
		tmp = flag * 1.0 / i;
		flag *= -1;
		sum += tmp;
	}

	printf("%lf", sum);
	return 0;
}


int d3p2y()
{
	int n = 10;

	int i;
	int sum = 0;
	int tmp = 1;
	for (i = 1; i <= n; i++)
	{
		tmp *= i;
		sum += tmp;
	}

	printf("%d\n", sum);
	return 0;
}