#include <stdio.h>
#include <string.h>

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
	if (n == 1)
	{
		return 1;
	}
	return n * mul(n - 1);
}

int myPow(int k, int n)
{
	if (n == 1)
	{
		return k;
	}
	return k * myPow(k, n - 1);
}

void printDigitNum(int n, int sn)
{
	if (n == 0)
	{
		return;
	}
	printDigitNum(n / sn, sn);
	putchar("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"[n % sn]);
}

int DigitNum(int n)
{
	if (n == 0)
	{
		return 0;
	}
	return n % 10 + DigitNum(n / 10);
}

int myStrlenN(char * str)
{
	int i;
	for (i = 0; str[i]; i++){}//字符串遍历
	return i;
}

int myStrlen(char * str)
{
	if (*str == '\0')
	{
		return 0;
	}
	return 1 + myStrlen(str + 1);
}

void reverse_string(char * str)
{
	int len = strlen(str) - 1;
	char tmp;

	if (str[0] == '\0')
	{
		return;
	}
	tmp = str[0];
	str[0] = str[len];
	str[len] = '\0'; //保证下一次能找到尾部
	reverse_string(str + 1);
	str[len] = tmp;
}

int main72()
{
	printDigitNum(1729, 16);
	printf("\n%d\n", DigitNum(1729));
	printf("%d\n", myStrlenN("bitekeji"));
	printf("%d\n", myStrlen("bitekeji"));
	char test[] = "bitekeji";
	reverse_string(test);
	puts(test);
	
	return 0;
}