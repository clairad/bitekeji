#include <stdio.h>

int count_one_bits_(unsigned int value)
{
	int i, count = 0;
	for (i = value; i; i /= 2)
	{
		count += i % 2;
	}
	return count;
}

int count_one_bits(unsigned int value)
{
	int count = 0;
	do{
		count++;
	} while (value &= value - 1);
	return count;
}

int main101()
{
	printf("%d\n", count_one_bits(1999^2299));
	return 0;
}