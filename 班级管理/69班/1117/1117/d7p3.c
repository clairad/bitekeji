#include <stdio.h>

int isRightDate(int y, int m, int d)
{
	return  !(d > 31 || m > 12 || d < 1 || m < 1 ||
			(m == 4 || m == 6 || m == 9 || m == 11) && d > 30 ||
			(m == 2) && d > 28 + (y % 400 == 0 ||
			y % 100 != 0 && y % 4 == 0));
}

int d7p3()
{
	int y = 0;
	int m = 0;
	int d = 0;

	scanf("%d%d%d", &y, &m, &d);

	if (isRightDate(y, m, d))
	{
		printf("合法\n");
	}
	else
	{
		printf("不合法\n");
	}

	return 0;
}