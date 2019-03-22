#include <stdio.h>
#include <math.h>

int main4()
{
	int a, b, i, min, max = 0, c;

	scanf("%d%d", &a, &b);
	/*
	min = a < b ? a : b;

	for (i = 2; i <= min; i++)
	{
		if (a % i == 0 && b % i == 0)
		{
			max = i;
		}
	}

	if (max == 0)
	{
		printf("两个数互质\n");
	}
	else
	{
		printf("最大公约数是%d\n", max);
	}*/

	while (c = a % b)
	{
		a = b;
		b = c;
	}

	if (b == 1)
	{
		printf("两个数互质\n");
	}
	else
	{
		printf("最大公约数是%d\n", b);
	}

	system("pause");
	return 0;
}