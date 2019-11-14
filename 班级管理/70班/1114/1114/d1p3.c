#include <stdio.h>

int d1p3()
{
	int y;
	scanf("%d", &y);

	if (y % 400 == 0 ||
		y % 100 != 0 && y % 4 == 0)
	{
		printf("是闰年");
	}
	else
	{ 
		printf("不是闰年");
	}
	return 0;
}

int d1p3p()
{
	int y, m, d;
	scanf("%d%d%d", &y, &m, &d);

	if ( m > 12 || m < 1 || d > 31 || d < 1 ||
		(m == 4 || m == 6 || m == 9 || m == 11) && d > 30 ||
		m == 2 && d > 28 + (y % 400 == 0 || y % 100 != 0 && y % 4 == 0)
		)
	{
		printf("不合法");
	}
	else
	{
		printf("合法");
	}
	return 0;
}