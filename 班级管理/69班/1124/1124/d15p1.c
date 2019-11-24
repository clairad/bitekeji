#include <stdio.h>

int fib(int n)
{
	if (n <= 2)
	{
		return 1;
	}
	return fib(n - 1) + fib(n - 2);
}

int mul(int n)
{
	if (n <= 1)
	{
		return 1;
	}
	return n * mul(n - 1); //Î²µÝ¹é
}

int pow(int m, int n)
{
	if (n <= 1)
	{
		return m;
	}
	return m * pow(m, n - 1);
}

int sum(int n)
{
	if (n <= 0)
	{
		return 0;
	}
	return n % 10 + sum(n / 10);
}

void printnum(int n, int m)
{
	if (n <= 0)
	{
		return;
	}
	printnum(n / m, m);
	putchar("0123456789ABCDEF"[n % m]);
}

int myStrlenNr(const char * str)
{
	int i;
	for (i = 0; str[i]; i++); //×Ö·û´®±éÀú
	return i;
}

int myStrlen(const char * str)
{
	if (*str)
	{
		return 1 + myStrlen(str + 1);
	}
	return 0;
}

void reverse_stringNr(char * str)
{
	int i = 0;
	int j = myStrlen(str) - 1;
	char tmp;

	for (; i < j; i++, j--)
	{
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
	}
}

void reverse_string(char * str)
{
	if (*str)
	{ 
		int i = myStrlen(str) - 1;
		char tmp;

		tmp = str[0];
		str[0] = str[i];
		str[i] = '\0';
		reverse_string(str + 1);
		str[i] = tmp;
	}
}

int d15()
{
	/*printf("%d\n", fib(5));
	printf("%d\n", mul(10));
	printf("%d\n", pow(2, 10));
	printf("%d\n", sum(1729));*/

	//printnum(102384, 16);

	//printf("%d\n", myStrlen("caixukun"));
	char str[20] = "qiaobiluo";

	reverse_string(str);

	puts(str);
	return 0;
}