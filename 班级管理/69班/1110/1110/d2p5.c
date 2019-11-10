#include <stdio.h>

int d2p5()
{
	int a, b;
	int max;

	scanf("%d%d", &a, &b);

	int smaller = a < b ? a : b;
	int i;
	for (i = 1; i <= smaller; i++)
	{
		if (a % i == 0 && b % i == 0)
		{
			max = i;
		}
	}

	printf("max = %d\n", max);
	return 0;
}

int d2p5p()
{
	int a, b;

	scanf("%d%d", &a, &b);

	int c;

	c = a % b;
	while (c)
	{
		a = b;
		b = c;
		c = a % b;
	}

	printf("max = %d\n", b);
	return 0;
}