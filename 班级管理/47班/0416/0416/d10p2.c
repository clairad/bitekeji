#include <stdio.h>

int main102()
{
	int n = 123456;
	int tmp = n;
	int i;
	
	for (i = 31; i >= 0; i -= 2)
	{
		putchar((n >> i & 1) + '0');
	}
	putchar('\n');
	for (i = 30; i >= 0; i -= 2)
	{
		putchar((n >> i & 1) + '0');
	}

	/*
	char num[34] = { 0 };
	for (i = 31; i >= 0; i--, n /= 2)
	{
		num[i / 2] = n % 2 + '0';
	}
	
	for (i = 0; num[i]; i+= 2)
	{
		putchar(num[i]);
	}
	putchar('\n');

	for (i = 1; num[i]; i += 2)
	{
		putchar(num[i]);
	}*/
	return 0;
}