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
	return n * mul(n - 1);
}

int pow(int n, int k)
{
	if (k <= 1)
	{
		return n;
	}
	return n * pow(n, k - 1);
}

int fib2(int n)
{
	int i;
	int an, an_1 = 1, an_2 = 1;
	if (n <= 2)
	{
		return 1;
	}
	for (i = 3; i <= n; i++)
	{
		an = an_1 + an_2;
		an_2 = an_1;
		an_1 = an;
	}
	return an;
}

void printnum(int n, int sn)
{
	if (n)
	{
		printnum(n / sn, sn);
		putchar("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"[n % sn]);
	}
}

int DigitSum(int n)
{
	if (n)
	{
		return n % 10 + DigitSum(n / 10);
	}
	return 0;
}

int mystrlen(char *str)
{
	if (*str == 0)
	{
		return 0;
	}
	return 1 + mystrlen(str + 1);
}

void reverse_string(char * str)
{
	int len = mystrlen(str);
	char tmp;
	if (*str)
	{ 
		tmp = str[0];
		str[0] = str[len - 1];
		str[len - 1] = 0;
		reverse_string(str + 1);
		str[len - 1] = tmp;
	}
}

int main()
{/*
	printf("%d\n", fib(10));
	printf("%d\n", mul(10));
	printf("%d\n", pow(2, 16));*/

	//12321 11 1234
	/*
	int a = 3601;
	int sn = 60;
	int i;
	int tmp, sum = 0;
	for (i = a; i; i /= sn) //ÊýÎ»±éÀú
	{
		tmp = i % sn;
		sum = sum * sn + tmp;
	}

	if (sum == a)
	{
		printf("Yes");
	}
	else
	{
		printf("No");
	}*/

	printnum(255, 16);
	printf("\n%d\n", DigitSum(1729));
	printf("%d\n", mystrlen("bitekeji"));

	char a[] = "bitekeji";
	
	reverse_string(a);
	puts(a);

	return 0;
}