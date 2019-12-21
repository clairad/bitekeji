//#include <stdio.h>
//#include <string.h>
//
//typedef struct HA{
//	char num[102];
//	int size;
//	char minusflag;
//}HighAcc;
//
//HighAcc dealNum(char * src)
//{
//	int i = 0, len = strlen(src);
//	HighAcc tmp = { 0 };
//	for (; i < len; i++)
//	{
//		tmp.num[i] = src[len - 1 - i] - '0';
//	}
//	tmp.size = len;
//	tmp.minusflag = 0;
//
//	return tmp;
//}
//
//HighAcc add(HighAcc num1, HighAcc num2)
//{
//	int longer = num1.size > num2.size ? num1.size : num2.size;
//	HighAcc res = { 0 };
//
//	int i;
//	int tmp;
//	for (i = 0; i < longer; i++)
//	{
//		tmp = num1.num[i] + num2.num[i] + res.num[i];
//		res.num[i] = tmp % 10;
//		res.num[i + 1] = tmp / 10;
//	}
//	res.size = longer + res.num[i];
//	return res;
//}
//
//int hacmp(HighAcc num1, HighAcc num2)
//{
//	if (num1.size > num2.size)
//	{
//		return 1;
//	}
//	else if (num1.size < num2.size)
//	{
//		return -1;
//	}
//
//	int i;
//	for (i = num1.size - 1; i >= 0; i--)
//	{
//		if (num1.num[i] > num2.num[i])
//		{
//			return 1;
//		}
//		else if (num1.num[i] < num2.num[i])
//		{
//			return -1;
//		}
//	}
//
//	return 0;
//}
//
//HighAcc sub(HighAcc num1, HighAcc num2)
//{
//	HighAcc res = { 0 };
//	HighAcc bigger = num1;
//	HighAcc smaller = num2;
//	int ret = hacmp(num1, num2);
//	if (ret == 0)
//	{
//		res.size = 1;
//		return res;
//	}
//	else if (ret < 0)
//	{
//		res.minusflag = 1;
//		bigger = num2;
//		smaller = num1;
//	}
//
//	int i;
//	int tmp;
//	for (i = 0; i < bigger.size; i++)
//	{
//		tmp = 10 + bigger.num[i] - smaller.num[i] + res.num[i];
//		res.num[i] = tmp % 10;
//		res.num[i + 1] = tmp / 10 - 1;
//	}
//
//	res.size = bigger.size;
//	for (i = bigger.size - 1; res.num[i] == 0; i--)
//	{
//		res.size--;
//	}
//	return res;
//}
//
//HighAcc mul(HighAcc num1, HighAcc num2)
//{
//	HighAcc res = { 0 };
//
//	if (num1.size == 1 && num1.num[0] == 0 ||
//		num2.size == 1 && num2.num[0] == 0)
//	{
//		res.size = 1;
//		return res;
//	}
//
//	int i, j;
//	int tmp;
//	for (i = 0; i < num1.size; i++)
//	{
//		for (j = 0; j < num2.size; j++)
//		{
//			tmp = num1.num[i] * num2.num[j] + res.num[i + j];
//			res.num[i + j] = tmp % 10;
//			res.num[i + j + 1] += tmp / 10;
//		}
//	}
//	res.size = i + j - !res.num[i + j - 1];
//	return res;
//}
//
//void printNum(HighAcc tmp)
//{
//	int i;
//	if (tmp.minusflag)
//	{
//		putchar('-');
//	}
//
//	for (i = tmp.size - 1; i >= 0; i--)
//	{
//		printf("%d", tmp.num[i]);
//	}
//}
//
//int main()
//{
//	char tmp[102] = { 0 };
//
//	scanf("%s", tmp);
//	HighAcc num1 = dealNum(tmp);
//	scanf("%s", tmp);
//	HighAcc num2 = dealNum(tmp);
//
//	HighAcc res = sub(num1, num2);
//
//	printNum(res);
//	return 0;
//}