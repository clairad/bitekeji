#include <stdio.h>

int p2_pow(int k, int n)
{
	if (n == 1)
	{
		return k;
	}
	return k * p2_pow(k, n - 1);
}

int p3_sum(int n)
{
	if (n)
	{
		return n % 10 + p3_sum(n / 10);
	}
	return 0;
}

int p5_strlenN(char * str)
{
	int i;
	for (i = 0; str[i]; i++);
	return i;
}

int p5_strlen(char * str)
{
	if (*str)
	{
		return 1 + p5_strlen(str + 1);
	}
	return 0;
}

int p6_mul(int n)
{
	if (n == 1)
	{
		return 1;
	}
	return n * p6_mul(n - 1);
}

void p7_printNum(int n)
{
	if (n)
	{
		p7_printNum(n / 10);
		printf("%d ", n % 10); 
	}
}

void switchNum(int n, int sn)
{
	if (n)
	{
		switchNum(n / sn, sn);
		putchar("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"[n % sn]);
	}
}

void reverse_string(char * str)
{
	int end = p5_strlen(str) - 1;
	char tmp = str[0];
	if (str[0])
	{ 
		str[0] = str[end];
		str[end] = '\0';
		reverse_string(str + 1);
		str[end] = tmp;
	}
}

int main72()
{
	//printf("%d\n", p2_pow(2, 5));
	//printf("%d\n", p6_mul(10));

	//printf("%d\n", p3_sum(1729));
	//p7_printNum(1729);
	//switchNum(274623, 30);
	//putchar('\n');
	printf("%d\n", p5_strlenN("bitekeji"));
	printf("%d\n", p5_strlen("bitekeji"));
	char arr[] = "bitekeji";
	reverse_string(arr);
	puts(arr);
	return 0;
}