#include <stdio.h>
#include <string.h>

int mul(char * a, int lena, char * b, int lenb, char * sum)
{
	int i, j;
	int tmp;

	for (i = 0; i < lena; i++)
	{
		for (j = 0; j < lenb; j++)
		{
			tmp = a[i] * b[j] + sum[i + j];
			sum[i + j] = tmp % 10;
			sum[i + j + 1] += tmp / 10;
		}
	}

	return lena + lenb - !sum[i + j - 1];
}

int add(char * a, char * b, int maxlen, char * sum)
{
	int i;
	int tmp;

	for (i = 0; i < maxlen; i++)
	{
		tmp = a[i] + b[i] + sum[i];
		sum[i] = tmp % 10;
		sum[i + 1] = tmp / 10;
	}

	/*
	for (i = 0; i < maxlen; i++)
	{
		tmp = a[i] + 10 - b[i] + sum[i];
		sum[i] = tmp % 10;
		sum[i + 1] = tmp / 10 - 1;
	}*/
	

	return maxlen + sum[i];
}

int dealNumber(char * a)
{
	int len = strlen(a);
	int i, j;
	char tmp;
	for (i = 0, j = len - 1; i <= j; i++, j--)
	{
		tmp = a[i];
		a[i] = a[j] - '0';
		a[j] = tmp - '0';
	}
	return len;
}

void outputNumber(char * a, int len)
{
	int i;
	for (i = len - 1; i >= 0; i--)
	{
		putchar(a[i] + '0');
	}
}

int main()
{
	char a[101] = { 0 };
	int lena;
	char b[101] = { 0 };
	int lenb;
	char sum[102] = { 0 };
	int lens;

	scanf("%s%s", a, b);

	lena = dealNumber(a);
	lenb = dealNumber(b);

	//lens = add(a, b, lena > lenb ? lena : lenb, sum);
	lens = mul(a, lena, b, lenb, sum);
	outputNumber(sum, lens);

	return 0;
}