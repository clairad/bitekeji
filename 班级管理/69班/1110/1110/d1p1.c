#include <stdio.h>
#include <math.h>

int main()
{
	int i;
	int n;
	
	for (n = 2; n <= 10000; n++)
	{
		int sqrtres = sqrt(n);
		for (i = 2; i <= sqrtres; i++)
		{
			if (n % i == 0)
			{
				break;
			}
		}

		if (i == sqrtres + 1)
		{
			printf("%d\n", n);
		}
	}
	return 0;
}
