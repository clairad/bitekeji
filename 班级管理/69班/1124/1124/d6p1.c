#include <stdio.h>

int countOneNum1(int n)
{
	int i;
	int count = 0;

	for (i = n; i; i /= 2)
	{
		count += i % 2;
	}

	return count;
}

int countOneNum2(int n)
{
	int count = 0;

	while (n)
	{
		n &= n - 1;
		count++;
	}
	
	return count;
}

int countOneNum(int n)
{
	n = (n & 0x55555555) + ((n >> 1) & 0x55555555);
	n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
	n = (n & 0x0f0f0f0f) + ((n >> 4) & 0x0f0f0f0f);
	n = (n & 0x00ff00ff) + ((n >> 8) & 0x00ff00ff);
	n = (n & 0x0000ffff) + ((n >> 16) & 0x0000ffff);

	return n;
}

int d6p1()
{
	printf("%d\n", countOneNum(1023));

	return 0;
}