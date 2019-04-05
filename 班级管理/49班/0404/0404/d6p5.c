#include <stdio.h>
#include <math.h>

int judgePrimeNumber(int n)
{
	int i;
	int tmp = sqrt(n);
	for (i = 2; i <= tmp; i++)
	{
		if (n % i == 0)
		{
			return 0;
		}
	}
	return 1;
}

int main65()
{
	int i;

	for (i = 2; i <= 1000; i++)
	{  
		if (judgePrimeNumber(i))
		{
			printf("%d\n", i);
		}
	}

	system("pause");
	return 0;
}