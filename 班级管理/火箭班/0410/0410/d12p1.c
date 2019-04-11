#include <stdio.h>

unsigned int reverse(unsigned int data)
{
	int tmp1, tmp2;
	int i, j;
	for (i = 0, j = 31; i < j; i++, j--)
	{
		tmp1 = !!(data & 1 << i);
		tmp2 = !!(data & 1 << j);
		data &= ~(1 << i);
		data &= ~(1 << j);
		data |= tmp1 << j;
		data |= tmp2 << i;
	}
	return data;
}

int main121()
{
	unsigned int n, sn = 2;
	scanf("%u", &n);
	int i;
	unsigned int tmp, sum = 0;
	printf("%u\n", reverse(n));
	return 0;
	for (i = 0; i < 32; n /= sn, i++)
	{
		tmp = n % sn;
		sum = sum * sn + tmp;
	}

	printf("%u\n", sum);
	
	return 0;
}