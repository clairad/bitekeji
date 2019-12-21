#include <stdio.h>
#include <string.h>

typedef struct HA{
	char num[102];
	int size;
	char minusflag;
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
	tmp.minusflag = 0;

	return tmp;
}

int hacmp(char * num1, int size1, char * num2, int size2)
{
	if (size1 > size2)
	{
		return 1;
	}
	else if (size1 < size2)
	{
		return -1;
	}

	int i;
	for (i = size1 - 1; i >= 0; i--)
	{
		if (num1[i] > num2[i])
		{
			return 1;
		}
		else if (num1[i] < num2[i])
		{
			return -1;
		}
	}

	return 0;
}

int sub(char * num1, int size1, char * num2, int size2)
{
	HighAcc res = { 0 };

	int i;
	int tmp;
	for (i = 0; i < size1; i++)
	{
		tmp = 10 + num1[i] - num2[i] + res.num[i];
		res.num[i] = tmp % 10;
		res.num[i + 1] = tmp / 10 - 1;
	}

	int count = 0;
	for (i = size1 - 1; res.num[i] == 0 && i >= 0; i--)
	{
		count++;
		num1[i] = 0;
	}

	for (; i >= 0; i--)
	{
		num1[i] = res.num[i];
	}

	/*int flag = 1;
	for (i = size1 - 1; i >= 0; i--)
	{
		if (res.num[i] == 0 && flag)
		{
			count++;
		}
		else
		{
			flag = 0;
		}
		num1[i] = res.num[i];
	}*/
	return count;
}

HighAcc div(HighAcc num1, HighAcc num2)
{
	int i;
	int count = 0;
	HighAcc res = { 0 };
	int flag = 0;

	for (i = num1.size - 1; i >= 0; i--)
	{
		while (hacmp(num1.num + i, num1.size - i, num2.num, num2.size) >= 0 && i < num1.size)
		{
			num1.size -= sub(num1.num + i, num1.size - i, num2.num, num2.size);
			count++;
		}
		if (flag == 0 && count != 0)
		{
			flag = 1;
			res.size = i + 1;
		}
		res.num[i] = count;
		count = 0;
	}

	return res;
}

HighAcc mod(HighAcc num1, HighAcc num2)
{
	int i;

	for (i = num1.size - 1; i >= 0; i--)
	{
		while (hacmp(num1.num + i, num1.size - i, num2.num, num2.size) >= 0 && i < num1.size)
		{
			num1.size -= sub(num1.num + i, num1.size - i, num2.num, num2.size);
		}
	}

	if (num1.size == 0)
	{
		num1.size = 1;
	}
	return num1;
}

void printNum(HighAcc tmp)
{
	int i;
	if (tmp.minusflag)
	{
		putchar('-');
	}

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

	HighAcc res1 = div(num1, num2);
	HighAcc res2 = mod(num1, num2);

	printNum(res1);
	putchar('\n');
	printNum(res2);
	return 0;
}