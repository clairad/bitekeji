#include <stdio.h>
#include <string.h>
//18446744073709551615

int mul(char *a, int lenA, char *b, int lenB, char *sum)
{
	int i, j, tmp;

	for (i = 0; i < lenA; i++)
	{
		for (j = 0; j < lenB; j++)
		{
			tmp = a[i] * b[j] + sum[i + j];
			sum[i + j] = tmp % 10;
			sum[i + j + 1] += tmp / 10;
		}
	}

	return lenA + lenB - !sum[i + j - 1];
}

int add(char *a, int lenA, char *b, int lenB, char *sum)
{
	int maxlen = lenA > lenB ? lenA : lenB;
	int i, tmp;

	for (i = 0; i < maxlen; i++)
	{
		tmp = a[i] + b[i] + sum[i];
		sum[i] = tmp % 10;
		sum[i + 1] = tmp / 10;
	}

	return maxlen + sum[i];
}

int dealNumber(char * str)
{
	int len = strlen(str);
	int i, j;
	char tmp;
	for (i = 0, j = len - 1; i <= j; i++, j--)
	{
		tmp = str[i];
		str[i] = str[j] - '0';
		str[j] = tmp - '0';
	}
	return len;
}

int printNumber(char * num, int len)
{
	int i;
	for (i = len - 1; i >= 0; i--)
	{
		putchar(num[i] + '0');
	}
}

int main()
{
	//char a[101] = { 0 };
	//char b[101] = { 0 };
	char sum[50000] = { 1 };
	char tmp[50000] = { 0 };

	//scanf("%s%s", a, b);
	//int lenA = dealNumber(a);
	//int lenB = dealNumber(b);
	
	int lenS = 1;//mul(a, lenA, b, lenB, sum);

	char i[3] = { 0 };
	for (i[1] = 0; i[1] <= 9 ; i[1]++)
	{
		for (i[0] = 0; i[0] <= 9; i[0]++)
		{
			if (i[0] == 0 && i[1] == 0)
			{
				continue;
			}
			lenS = mul(sum, lenS, i, !!i[1] + 1, tmp);
			memcpy(sum, tmp, lenS);
			memset(tmp, 0, lenS);
		}
	}

	printNumber(sum, lenS);
	return 0;
}