#include <stdio.h>

int checkNum(int a, int b, int c)
{
	int res = 0;
	res |= 1 << a % 10;
	res |= 1 << a / 10 % 10;
	res |= 1 << a / 100;

	res |= 1 << b % 10;
	res |= 1 << b / 10 % 10;
	res |= 1 << b / 100;

	res |= 1 << c % 10;
	res |= 1 << c / 10 % 10;
	res |= 1 << c / 100;

	return res == 0x3fe;
}

int main111p()
{
	int a, b, c;

	for (a = 123; a <= 329; a++)
	{
		for (b = 246; b <= 658; b++)
		{
			for (c = 369; c <= 987; c++)
			{
				if (b == a * 2 && c == a * 3 && checkNum(a, b, c))
				{
					printf("%d %d %d\n", a, b, c);
				}
			}
		}
	}

	return 0;
}