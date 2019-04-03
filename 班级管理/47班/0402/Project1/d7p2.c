#include <stdio.h>
#include <string.h>

int myPow(int k, int n)
{
	if (n == 1)
	{
		return k;
	}
	return k * myPow(k, n - 1);
}

int DigitSum(int n)
{
	if (n == 0)
	{
		return 0;
	}
	return n % 10 + DigitSum(n / 10);
}

int reverse_string(char * string)
{
	//int len = strlen(string);
	//static int i = 0;

	//reverse_string(string + 1);
}

int myStrlen(char * str)
{
	if (*str == '\0')
	{
		return 0;
	}
	return 1 + myStrlen(str + 1);
}

int mul(int n)
{
	if (n == 1)
	{
		return 1;
	}
	return n * mul(n - 1);
}

void PrintSum(int n, int sn)
{
	if (n == 0)
	{
		return;
	}
	
	PrintSum(n / sn, sn);
	putchar("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"[n % sn]);
}

int main()
{
	printf("%d\n", myPow(2, 3));
	printf("%d\n", DigitSum(1973));
	printf("%d\n", myStrlen("bitekeji"));
	printf("%d\n", mul(10));
	PrintSum(20160, 20);
	putchar('\n');
	system("pause");
	return 0;
}