#include <stdio.h>

int p7()
{
	int n;
	int sum;
	int cover = 0;

	int i;
	for (i = 1; i <= 20; i++)
	{
		sum = n = i;
		cover = 0;
		while (n > 0)
		{
			cover += n % 4;
			n /= 4;
			sum += n;
			if (cover >= 4)
			{
				sum++;
				cover -= 4;
			}
		}


		printf("%d %d %d\n", i, cover, sum);
	}

	return 0;
}