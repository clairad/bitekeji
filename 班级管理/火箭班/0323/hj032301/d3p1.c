#include <stdio.h>

void printArray(int a[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	putchar('\n');
}

int main6()
{
	int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int b[10] = { 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };
	int i, tmp;

	printArray(a, 10);
	printArray(b, 10);

	for (i = 0; i < 10; i++)
	{
		tmp = a[i];
		a[i] = b[i];
		b[i] = tmp;
	}

	printArray(a, 10);
	printArray(b, 10);
	system("pause");
	return 0;
}