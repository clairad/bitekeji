#include <stdio.h>
#define SIZE(a) (sizeof(a) / sizeof(a[0]))

void divide1(int * a, int n)
{
	int s[128] = { 0 };
	int d[128] = { 0 };
	int i, counts = 0, countd = 0;

	for (i = 0; i < n; i++)
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

	for (; i < n; i++)
	{
		a[i] = d[i - counts];
	}
}

void divide(int * a, int n)
{
	int start = 0;
	int end = n - 1;
	int tmp;

	while (a[start++] % 2);
	while (a[end--] % 2 == 0);
	while (start < end)
	{
		tmp = a[end + 1];
		a[end + 1] = a[start - 1];
		a[start - 1] = tmp;

		while (a[start++] % 2);
		while (a[end--] % 2 == 0);
	}
}

void printArray(int * a, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	putchar('\n');
}


int main131()
{
	int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	divide(a, SIZE(a));
	printArray(a, SIZE(a));
	
	return 0;
}