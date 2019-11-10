#include <stdio.h>
#include <math.h>

int d4p2p()
{
	int i;
	int addflag = 10;
	int n = 1;
	int sum = 0, j;

	for (i = 1; i < 100000000; i++)
	{
		if (i == addflag)
		{
			n++;
			addflag *= 10;
		}

		for (j = i; j; j /= 10)
		{
			sum += pow(j % 10, n);
		}

		if (sum == i)
		{
			printf("%d\n", sum);
		}
		sum = 0;
	}
	return 0;
}

int d4p2()
{
	int i;
	int a, b, c;

	for (i = 100; i < 1000; i++)
	{
		a = i % 10;
		b = i / 10 % 10;
		c = i / 100;

		if (i == a * a * a + b * b * b + c * c * c)
		{
			printf("%d\n", i);
		}
	}

	return 0;
}