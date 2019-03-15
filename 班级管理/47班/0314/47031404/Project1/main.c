#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <Windows.h>

int main()
{/*
	int a = 4, b = 5, tmp;
	printf("交换前：a = %d, b = %d\n", a, b);
	tmp = a;
	a = b;
	b = tmp;
	a = a + b;
	b = a - b;
	a = a - b;

	printf("交换后：a = %d, b = %d\n", a, b);
	*//*
	int i;
	int tmp, max = 0x80000000;

	for (i = 0; i < 10; i++)
	{ 
		scanf("%d", &tmp);
		if (tmp > max)
		{
			max = tmp;
		}
	}
	
	printf("%d\n", max);*/
	/*
	int a, b, c;
	int tmp;
	scanf("%d%d%d", &a, &b, &c);

	if (a < b)
	{
		tmp = a;
		a = b;
		b = tmp;
	}

	if (c > b)
	{
		if (c > a)
		{
			printf("%d %d %d\n", c, a, b);
		}
		else
		{
			printf("%d %d %d\n", a, c, b);
		}
	}
	else
	{
		printf("%d %d %d\n", a, b, c);
	}
	*/
	int i;
	int a, b, max, min, c;
	scanf("%d%d", &a, &b);
	/*
	if (a < b)
	{
		min = a;
	}
	else
	{
		min = b;
	}*//*
	min = a < b ? a : b;
	for (i = 2; i <= min; i++)
	{
		if (a % i == 0 && b % i == 0)
		{
			max = i;
		}
	}*/

	while (c = a % b)
	{
		a = b;
		b = c;
	}

	printf("最大公约数是%d\n", b);
	system("pause");
	
	return 0;
}