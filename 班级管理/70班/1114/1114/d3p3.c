#include <stdio.h>

int d3p3()
{
	int i;

	int count = 0;

	for (i = 0; i <= 1000; i++)
	{
		if (i % 10 == 9)
		{
			count++;
		}

		if (i / 10 % 10 == 9)
		{
			count++;
		}

		if (i / 100 == 9)
		{
			count++;
		}
	}

	printf("%d", count);
	return 0;
}