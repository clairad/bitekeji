#include <stdio.h>

int main131()
{
	int a[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int i = 0, j = 9;

	int tmp;

	while (a[i++] % 2 && i < 10);
	while (a[j--] % 2 == 0 && j >= 0);
	while (i - 1 < j + 1)
	{
		tmp = a[i - 1];
		a[i - 1] = a[j + 1];
		a[j + 1] = tmp;

		while (a[i++] % 2);
		while (a[j--] % 2 == 0);
	}


	/*
	int s[10] = { 0 };
	int d[10] = { 0 };
	int i, counts = 0, countd = 0;

	for (i = 0; i < 10; i++)
	{
		if (a[i] % 2)
		{
			s[counts++] = a[i];
		}
		else
		{
			d[countd++] = a[i];
		}
	}

	for (i = 0; i < counts; i++)
	{
		a[i] = s[i];
	}

	for (i = 0; i < countd; i++)
	{
		a[counts + i] = d[i];
	}
	*/
	for (i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);
	}


	return 0;
}