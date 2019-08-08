#include <stdio.h>

int fib(int n)
{
	if (n <= 2)
	{
		return 1;
	}
	return fib(n - 1) + fib(n - 2);
}

int fibNr(int n)
{
	if (n <= 2)
	{
		return 1;
	}

	int an, an_1 = 1, an_2 = 1;

	int i;
	for (i = 3; i <= n; i++)
	{
		an = an_1 + an_2;
		an_2 = an_1;
		an_1 = an;
	}

	return an;
}

int mul(int n)
{
	if (n <= 1)
	{
		return 1;
	}
	return n * mul(n - 1); //Î²µÝ¹é
}

int mPow(int m, int n)
{
	if (n == 1)
	{
		return m;
	}
	return m * mPow(m, n - 1);
}

int DigitSum(int n)
{
	if (n == 0)
	{
		return 0;
	}
	return n % 10 + DigitSum(n / 10);
}

int myStrlen(const char * str)
{
	if (*str == '\0')
	{
		return 0;
	}
	return 1 + myStrlen(str + 1);
}

void printNum(int n, int m)
{
	if (n == 0)
	{
		return;
	}
	
	printNum(n / m, m);
	putchar("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"[n % m]);
}

void reverse_string(char * str)
{
	if (*str)
	{
		int tmp;
		int end = myStrlen(str) - 1;

		tmp = *str;
		*str = str[end];
		str[end] = '\0';
		reverse_string(str + 1);
		str[end] = tmp;
	}
}

int smain()
{
	//printf("%d\n", myStrlen("bitekeji"));
	//printNum(10000, 36);
	char str[] = "bitekeji";
	reverse_string(str);
	puts(str);
	return 0;
}
