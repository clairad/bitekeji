#include <stdio.h>
#include <ctype.h>

int isDiff(int a, int b, int c, int d, int e)
{
	char tmp = 0;

	tmp |= 1 << (a - 1);
	tmp |= 1 << (b - 1);
	tmp |= 1 << (c - 1);
	tmp |= 1 << (d - 1);
	tmp |= 1 << (e - 1);

	return tmp == 31;
}

int isDiff2(char * str)
{
	int ans = 0;
	char tmp;

	int i;
	for (i = 0; str[i]; i++)
	{
		if (isalpha(str[i]))
		{
			tmp = (str[i] & 31) - 1;
			ans |= 1 << tmp;
		}
	}

	return ans == (1 << 26) - 1;
}


int d10p1()
{
	int a, b, c, d, e;

	for (a = 1; a <= 5; a++)
	{
		for (b = 1; b <= 5; b++)
		{
			for (c = 1; c <= 5; c++)
			{
				for (d = 1; d <= 5; d++)
				{
					for (e = 1; e <= 5; e++)
					{
						if ((b == 2) + (a == 3) == 1 &&
							(b == 2) + (e == 4) == 1 &&
							(c == 1) + (d == 2) == 1 &&
							(c == 5) + (d == 3) == 1 &&
							(e == 4) + (a == 1) == 1 &&
							isDiff(a, b, c, d, e))
						{
							printf("a第%d\nb第%d\nc第%d\nd第%d\ne第%d\n", a, b, c, d, e);
						}
					}
				}
			}
		}
	}

	return 0;
}

int d10p2()
{
	int tmp[4] = { 0 };

	int i;
	for (i = 0; i < 4; i++)
	{
		tmp[i] = 1;
		if ((tmp[0] != 1) + (tmp[2] == 1) +
			(tmp[3] == 1) + (tmp[3] != 1) == 3)
		{
			printf("%c是凶手", 'A' + i);
		}
		tmp[i] = 0;
	}

	return 0;
}