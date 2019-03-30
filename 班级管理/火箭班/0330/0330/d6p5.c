#include <stdio.h>
#include <math.h>

int judge(int n)
{
	int tmp, i;

	tmp = sqrt(n);
	for (i = 2; i <= tmp; i++)
	{
		if (n % i == 0)
		{
			return 0;
		}
	}
	return 1;
}

int main()
{
	int i;
	for (i = 2; i < 100; i++)
	{
		if (judge(i))
		{
			printf("%d\n", i);
		}
	}

	return 0;
}