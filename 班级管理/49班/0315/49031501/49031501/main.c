#include <stdio.h>
int main()
{
	int y;
	scanf("%d", &y);
	if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0))
	{
		printf("是闰年");
	}
	else
	{
		printf("是平年");
	}
	return 0;
}
