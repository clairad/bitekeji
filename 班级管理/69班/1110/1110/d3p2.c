#include <stdio.h>

int d3p2()
{
	int i;

	double sum = 0;
	double tmp = 0;
	int flag = 1;
	for (i = 1; i <= 100; i++)
	{
		tmp = flag * 1.0 / i;
		flag *= -1;
		sum += tmp;
	}

	printf("%.4lf\n", sum);
	return 0;
}