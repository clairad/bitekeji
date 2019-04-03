#include <stdio.h>
#include <math.h>

int judge(int n)
{
	int i, tmp;
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

int main65()
{
	int i, count = 0;

	for (i = 2; i < 10000; i++)
	{
		if (judge(i))
		{
			printf("%4d ", i);
			count++;
			if (count % 10 == 0)
			{
				putchar('\n');
			}
		}
	}
	
	system("pause");
	return 0;
}