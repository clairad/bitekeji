#include <stdio.h>

void init(int data[], int a[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		a[i] = data[i];
	}
}

void reverse(int a[], int n)
{
	int i, j;
	int tmp;
	for (i = 0, j = n - 1; i < j; i++, j--)
	{
		tmp = a[i];
		a[i] = a[j];
		a[j] = tmp;
	}
}

void empty(int a[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		a[i] = 0;
	}
}

void printArray(int a[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	putchar('\n');
}

int main64()
{
	int data[10] = { 9, 5, 1, 7, 4, 8, 6, 2 };
	int a[10] = { 0 };

	init(data, a, 10);
	printArray(a, 10);
	reverse(a, 10);
	printArray(a, 10);
	empty(a, 10);
	printArray(a, 10);

	system("pause");
	return 0;
}