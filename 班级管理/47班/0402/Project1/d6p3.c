#include <stdio.h>

int judgeLeapYear(int y)
{
	return y % 400 == 0 || (y % 4 == 0 && y % 100 != 0);
}

int main63()
{
	int n;
	scanf("%4d", &n);
	printf("%d %d\n",n , judgeLeapYear(n));
	system("pause");
	return 0;
}