#include <stdio.h>

void printlog(int a[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

int main0()
{
	int a[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int b[10] = { 10, 11, 12, 13, 14, 15, 16, 17, 18, 19 };
	int i;
	int tmp;

	printlog(a, 10);
	printlog(b, 10);

	for (i = 0; i < 10; i++) //Êý×é±éÀú
	{
		tmp = a[i];
		a[i] = b[i];
		b[i] = tmp;
	}
	
	printlog(a, 10);
	printlog(b, 10);

	system("pause");
	return 0;
}