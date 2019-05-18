#include <stdio.h>
#include <string.h>
#include <math.h>

//可移植性，可读性，复用性
//单一的功能

void printform(int n)
{
	int i, j;

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= i; j++)
		{
			printf("%d*%d=%d ", j, i, i * j);
		}
		putchar('\n');
	}
}

void swapArgs(int *pa, int *pb)
{
	int tmp;

	tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}

#define SIZE(a) (sizeof(a) / sizeof(a[0]))
#define swapArgs2(a, b) {  \
							int tmp = a; \
							a = b; \
							b = tmp; \
						}
//#define MAX 1000 + 3

int leap_year(int y)
{
	return y % 400 == 0 || (y % 100 != 0 && y % 4 == 0);
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

void empty(int a[], int n)
{
	memset(a, 0, n * sizeof(int));
}

void reverse(int a[], int n)
{
	int i, j;
	for (i = 0, j = n - 1; i < j; i++, j--)
	{
		swapArgs(&a[i], &a[j]);
	}
}

//            出参    入参            入参
void init(int dst[], int n, const int src[])
{
	int i;
	for (i = 0; i < n; i++)
	{
		dst[i] = src[i];
	}
}

int prime(int n)
{
	int i;
	for (i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)
		{
			return 0;
		}
	}
	return 1;
}

int main6()
{	
#if 0 //q1
	int n;
	scanf("%d", &n);

	printform(n);
#endif

#ifdef MAX //q2
	int a = 3, b = 4;

	//swapArgs(&a, &b);
	swapArgs2(a, b);
	printf("a = %d, b = %d", a, b);
#endif

#if 0
	printf("%d", leap_year(1200));
#endif

#if 0
	int a[3] = { 1, 2, 3 };
	memset(a, 0, sizeof(a));
	//bzero(a, sizeof(a));
	printf("%08x %08x %08x\n", a[0], a[1], a[2]);
#endif

#if 0
	int a[10] = { 0 };
	int b[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int i;
	init(a, 10, b);
	printArray(a, 10);
	reverse(a, 10);
	printArray(a, 10);
	empty(a, 10);
	printArray(a, 10);
#endif

#if 1
	int i;

	for (i = 2; i <= 10000; i++) //数字遍历
	{
		if (prime(i))
		{
			printf("%d ", i);
		}
	}
#endif

	return 0;
}