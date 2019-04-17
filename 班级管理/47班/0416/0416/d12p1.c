#include <stdio.h>

unsigned int reverse_bit(unsigned int value)
{
	int i, count = 0;
	int tmp, sum = 0;
	for (i = 0; i < 32; i++, value /= 2)
	{
		tmp = value % 2;
		sum = sum * 2 + tmp;
	}
	return sum;
}

int main121()
{
	printf("%u", reverse_bit(25));
	return 0;
}