#include <stdio.h>

int main5()
{
	int a, b, max = 0, c;
	int i;

	scanf("%d%d", &a, &b);
	/*
	for (i = 2; i < (a < b ? a : b); i++)
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

	if (b == 1)
	{
		printf("互质\n");
	}
	else
	{
		printf("最大公约数是%d\n", b);
	}

	system("pause");
	return 0;
}