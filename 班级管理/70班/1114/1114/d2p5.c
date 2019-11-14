#include <stdio.h>

int d2p5p()
{
	int a, b;
	int max = 1;

	scanf("%d%d", &a, &b);

	int c = a % b;

	while (c)
	{
		a = b;
		b = c;
		c = a % b;
	}

	printf("%d", b);

	return 0;
}

int d2p5()
{
	int a, b;
	int max = 1;

	scanf("%d%d", &a, &b);
	int smaller = a < b ? a : b;

	int i;
	for (i = 2; i <= smaller; i++)
	{
		if (a % i == 0 && b % i == 0)
		{
			max = i;
		}
	}

	printf("%d\n", max);

	printf("%d", (a / max) * (b / max) * max);
	return 0;
}