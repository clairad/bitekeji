#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

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

void d1p1()
{
	int i, j;

	for (i = 0; i <= 100000; i++)
	{
#if 0
		for (j = 2; j <= sqrt(i); j++)
		{
			if (i % j == 0)
			{
				break;
			}
		}

		if (j > sqrt(i))
		{
			printf("%d\n", i);
		}
#else
		if (prime(i))
		{
			printf("%d\n", i);
		}
#endif
	}
}

void d1p2(int n)
{
	int i, j;

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= i; j++)
		{
			printf("%d*%d=%2d ", j, i, i * j);
		}
		putchar('\n');
	}

}

void d3p2()
{
	int i;
	double sum = 0;
	int flag = 1;

	for (i = 1; i <= 100; i++)
	{
		sum += flag * 1.0 / i;
		flag *= -1;
	}
	printf("%.8lf\n", sum);
}

void d4p1(int n)
{
	int i, j;

	for (i = 1; i <= n; i++)
	{
#if 0
		for (j = 1; j <= n - i; j++)
		{
			putchar(' ');
		}

		for (j = 1; j <= 2 * i - 1; j++)
		{
			putchar('*');
		}
#else
		for (j = 1; j < n + i; j++)
		{
			putchar(j <= n - i ? ' ' : '*');
		}
#endif
		putchar('\n');
	}

	for (i = n - 1; i > 0; i--)
	{
		for (j = 1; j < n + i; j++)
		{
			putchar(j <= n - i ? ' ' : '*');
		}
		putchar('\n');
	}
	
}

void d4p2()
{
	int i;
	int j;
	int num = 0;
	int modflag = 1;
	int sum = 0;

	for (i = 0; i < 1000000000; i++)
	{
		if (i % modflag == 0)
		{
			num++;
			modflag *= 10;
		}

		for (j = i; j; j /= 10)
		{
			sum += pow(j % 10, num);
		}

		if (sum == i)
		{
			printf("%d\n", i);
		}
		sum = 0;
	}
}

int fib(int n)
{
	int i;
	if (n <= 2)
	{
		return 1;
	}
	int an, an_1 = 1, an_2 = 1;
	for (i = 3; i <= n; i++)
	{
		an = an_1 + an_2;
		an_2 = an_1;
		an_1 = an;
	}
	return an;
}

int fib2(int n)
{
	if (n <= 2)
	{
		return 1;
	}
	return fib2(n - 1) + fib(n - 2);
}

int mul(int n)
{
	if (n <= 1)
	{
		return 1;
	}
	return n * mul(n - 1);
}

int mpow(int n, int m)
{
	if (m = 1)
	{
		return n;
	}
	return n * mpow(n, m - 1);
}

int sum(int n)
{
	if (n == 0)
	{
		return 0;
	}
	return n % 10 + sum(n / 10);
}

void d7p1()
{
	printf("%d\n", fib(10));
}

void reverse_string(char * string)
{
	if (!*string)
	{
		return;
	}
	char tmp;
	int len = strlen(string);

	tmp = string[0];
	string[0] = string[len - 1];
	string[len - 1] = 0;
	reverse_string(string + 1);
	string[len - 1] = tmp;
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

void wordReverse(char * start, char * end)
{
	int length = end - start;
	int i;
	char tmp;

	for (i = 0; i < length / 2; i++)
	{
		tmp = start[i];
		start[i] = start[length - 1 - i];
		start[length - 1 - i] = tmp;
	}
}

void reverseStringN(char * str)
{
	int i;
	char * start = str;
	char * end;

	for (i = 0; str[i]; i++)
	{
		if (str[i] == ' ')
		{
			end = str + i;
			wordReverse(start, end);
			start = end + 1;
		}
	}
	wordReverse(start, str + i);
	wordReverse(str, str + i);
}

void reverseString(char * str)
{
	char * tmp = str;
	char * res = (char *)malloc(strlen(str) + 1);
	memset(res, 0, strlen(str));

	while (tmp = strrchr(str, ' '))
	{
		strcat(res, tmp + 1);
		strcat(res, " ");
		*tmp = 0;
	}
	strcat(res, str);
	strcpy(str, res);
	free(res);
}

int main()
{
	//d1p1();
	//y % 400 == 0 || y % 100 != 0 && y % 4 == 0
	/*for (i = 1; i < smaller; i++)
	{
		if (a % i == 0 && b % i == 0)
		{
			max = i;
		}
	}*

	d1p2(6);*/
	//d3p2();
	//d4p1(5);
	//d4p2();
	//d7p1();
	char str[] = "This class is too hard!";
	/*reverse_string(str);
	puts(str);*/

	//printNum(64235, 16);
	reverseString(str);
	puts(str);
	return 0;
}