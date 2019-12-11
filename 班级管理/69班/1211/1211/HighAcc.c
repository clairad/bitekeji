#include <stdio.h>
#include <string.h>

typedef struct HA{
	char num[102];
	int size;
}HighAcc;

HighAcc dealNum(char * src)
{
	int i = 0, len = strlen(src);
	HighAcc tmp = { 0 };
	for (; i < len; i++)
	{
		tmp.num[i] = src[len - 1 - i] - '0';
	}
	tmp.size = len;

	return tmp;
}

HighAcc add(HighAcc num1, HighAcc num2)
{
	int longer = num1.size > num2.size ? num1.size : num2.size;
	HighAcc res = { 0 };

	int i;
	int tmp;
	for (i = 0; i < longer; i++)
	{
		tmp = num1.num[i] + num2.num[i] + res.num[i];
		res.num[i] = tmp % 10;
		res.num[i + 1] = tmp / 10;
	}
	res.size = longer + res.num[i];
	return res;
}

HighAcc mul(HighAcc num1, HighAcc num2)
{
	HighAcc res = { 0 };

	if (num1.size == 1 && num1.num[0] == 0 ||
		num2.size == 1 && num2.num[0] == 0)
	{
		res.size = 1;
		return res;
	}

	int i, j;
	int tmp;
	for (i = 0; i < num1.size; i++)
	{
		for (j = 0; j < num2.size; j++)
		{
			tmp = num1.num[i] * num2.num[j] + res.num[i + j];
			res.num[i + j] = tmp % 10;
			res.num[i + j + 1] += tmp / 10;
		}
	}
	res.size = i + j - !res.num[i + j - 1];
	return res;
}

void printNum(HighAcc tmp)
{
	int i;
	for (i = tmp.size - 1; i >= 0; i--)
	{
		printf("%d", tmp.num[i]);
	}
}

int main()
{
	char tmp[102] = { 0 };

	scanf("%s", tmp);
	HighAcc num1 = dealNum(tmp);
	scanf("%s", tmp);
	HighAcc num2 = dealNum(tmp);

	HighAcc res = mul(num1, num2);

	printNum(res);
	return 0;
}