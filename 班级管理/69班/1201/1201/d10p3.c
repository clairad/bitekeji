#include <stdio.h>

void printYH(int n)
{
	int form[20][20] = { 0 };

	int i, j;
	for (i = 0; i < n; i++)
	{
		form[i][0] = 1;
		for (j = 1; j <= i; j++)
		{
			form[i][j] = form[i - 1][j] + form[i - 1][j - 1];
		}
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j <= i; j++)
		{
			printf("%d ", form[i][j]);
		}
		putchar('\n');
	}
}

void printArray(int * src, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		printf("%d ", src[i]);
	}
	putchar('\n');
}

void printYHEvolution(int n)
{
	int form[20] = { 1 };

	int i, j;
	printf("1\n");
	for (i = 1; i < n; i++)
	{
		for (j = i; j > 0; j--)
		{
			form[j] += form[j - 1];
		}
		printArray(form, i + 1);
	}
}

int main()
{
	printYHEvolution(10);

	return 0;
}