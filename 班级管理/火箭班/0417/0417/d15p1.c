#include <stdio.h>
#define SIZE(a) (sizeof(a) / sizeof(a[0]))

int main151()
{
	int a[] = { 8, 10, 8, 2, 11, 9, 12, 11, 9, 2 };
	int i, sum = 0;
	int pos;
	int num1 = 0, num2 = 0;

	for (i = 0; i < SIZE(a); i++)
	{
		sum ^= a[i];
	}

	for (i = 0; i < 32; i++)
	{
		if (sum & 1 << i)
		{
			pos = i;
			break;
		}
	}

	for (i = 0; i < SIZE(a); i++)
	{
		if (a[i] & 1 << pos)
		{
			num1 ^= a[i];
		}
		else
		{
			num2 ^= a[i];
		}
	}

	printf("%d %d\n", num1, num2);
	return 0;
}