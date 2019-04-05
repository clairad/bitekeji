#include <stdio.h>

int judgeLeapYear(int y) //驼峰式
{
	return y % 400 == 0 || (y % 4 == 0 && y % 100 != 0);
}

int main63()
{
	if (judgeLeapYear(1999))
	{
		printf("闰年\n");
	}
	else
	{
		printf("平年\n");
	}

	system("pause");
	return 0;
}