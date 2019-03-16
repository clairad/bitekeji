#include <stdio.h>
#define SECOFYEAR (365 * 24 * 3600UL)
int i;

int main()
{/*
	int i = 3;

	if (i == 1)
	{
		printf("i是1\n");
	}
	else if (i == 2)
	{
		printf("i是2\n"); 
	}
	else
	{
		printf("i不是1 2\n");
	}*/
	int year;
	unsigned int month, day, flag = 0;
	scanf("%d%d%d", &year, &month, &day);
	/*
	if ((year % 100 != 0 && year % 4 == 0) || year % 400 == 0)
	{
		flag = 1;
	}
	
	if (month == 0 || month > 12 || day == 0)
	{
		printf("不合理\n");
		return 0;
	}
	
	if (month == 2)
	{
		if (day > 28 + flag)
		{
			printf("不合理\n");
			return 0;
		}
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		if (day > 30)
		{
			printf("不合理\n");
			return 0;
		}
	}
	else
	{
		if (day > 31)`	
		{
			printf("不合理\n");
			return 0;
		}
	}*/
	if ((month == 0 || month > 12 || day == 0) ||
		(month == 2 && day > 28 + ((year % 100 != 0 && year % 4 == 0) || year % 400 == 0)) ||
		((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) || day > 31)
	{
		printf("不合理\n");
	}
	else
	{ 
		printf("合理\n");
	}
	return 0;
}