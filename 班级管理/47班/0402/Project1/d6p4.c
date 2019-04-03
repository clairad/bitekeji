#include <stdio.h>

void init(int * data, int size, int input[])
{
	int i;
	for (i = 0; i < size; i++)
	{
		data[i] = input[i];
	}
}

void reverse(int data[], int size)
{
	int i, j;
	int tmp;
	for (i = 0, j = size - 1; i < j; i++, j--)
	{
		tmp = data[i];
		data[i] = data[j];
		data[j] = tmp;
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

void printlog(int a[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

int main64()
{
	int data[10] = { 0 };
	int input[100] = { 2, 5, 7, 9, 1, 4, 3, 8 };

	init(data, 10, input);
	printlog(data, 10);
	reverse(data, 10);
	printlog(data, 10);
	empty(data, 10);
	printlog(data, 10);
	system("pause");
	return 0;
}