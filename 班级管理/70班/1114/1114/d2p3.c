#include <stdio.h>

int d2p3p()
{
	int tmp, max = 0x80000000;
	int nxt = 0x80000000;

	int i;
	for (i = 0; i < 10; i++)
	{
		scanf("%d", &tmp);

		if (tmp > max)
		{
			nxt = max;
			max = tmp;
		}
		else if (tmp > nxt)
		{
			nxt = tmp;
		}
	}

	printf("%d", nxt);
	return 0;
}

int d2p3()
{
	int tmp, max = 0x80000000;

	int i;
	for (i = 0; i < 10; i++)
	{
		scanf("%d", &tmp);

		if (tmp > max)
		{
			max = tmp;
		}
	}

	printf("%d", max);
	return 0;
}