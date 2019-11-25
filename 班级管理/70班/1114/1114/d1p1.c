#include <stdio.h>
#include <math.h>

int d1p1()
{
	int n;
	int i;
	int tmp;
	//scanf("%d", &n);

	for (n = 2; n < 10000000; n++)
	{ 
		tmp = sqrt(n);
		for (i = 2; i <= tmp; i++)
		{
			if (n % i == 0)
			{
				break;
			}
		}

		if (i > tmp)
		{ 
			printf("%d\n", n);
		}
	}
	return 0;
}