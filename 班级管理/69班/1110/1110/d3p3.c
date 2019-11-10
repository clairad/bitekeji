#include <stdio.h>

/*
数位遍历：
for (i = n; i; i /= m) i % m;

i % m可以完成对n在m进制下每一位的遍历
*/

int d3p3p()
{
	int n = 1234;
	int m = 8;

	int i;
	int sum = 0;
	for (i = n; i; i /= m) //数位遍历
	{
		sum = sum * m + i % m;
	}

	printf("%d", sum);
	return 0;
}

int d3p3()
{
	int i;
	int count = 0;

	for (i = 0; i <= 100; i++)
	{
		if (i % 10 == 9)
		{
			count++;
		}

		if (i / 10 == 9)
		{
			count++;
		}
	}

	printf("%d", count);
	return 0;
}
