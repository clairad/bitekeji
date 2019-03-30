#include <stdio.h>

void init(int in[], int data[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		in[i] = data[i];
	}
}

void empty(int data[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		data[i] = 0;
	}
}

void reverse(int data[], int n)
{
	int tmp;
	int i, j;
	for (i = 0, j = n - 1; i < j; i++, j--)
	{
		tmp = data[i];
		data[i] = data[j];
		data[j] = tmp;
	}
}

void printArray(int data[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%d ", data[i]);
	}
	putchar('\n');
}

int main64()
{
	int a[10] = { 0 };
	int b[6] = { 1, 2, 3, 4, 5, 6 };

	init(a, b, 6);
	printArray(a, 10);
	reverse(a, 10);
	printArray(a, 10);
	empty(a, 10);
	printArray(a, 10);
	return 0;
}