#include <stdio.h>

int judge(int a, int b, int c)
{
	int i = 0;
	i |= 1 << a % 10;
	i |= 1 << a / 10 % 10;
	i |= 1 << a / 100;
	//0000000000
	//9876543210
	//1111111110

	i |= 1 << b % 10;
	i |= 1 << b / 10 % 10;
	i |= 1 << b / 100;

	i |= 1 << c % 10;
	i |= 1 << c / 10 % 10;
	i |= 1 << c / 100;

	return i == 0x3fe;
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
				if (judge(a, b, c) && b == 2 * a && c == 3 * a)
				{
					printf("%d %d %d\n", a, b, c);
				}
			}
		}
	}

	system("pause");
	return 0;
}