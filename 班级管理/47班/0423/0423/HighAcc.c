#include <stdio.h>
#include <string.h>

typedef struct {
	char data[1000];
	int len;
}HighAcc;

HighAcc mul(HighAcc a, HighAcc b)
{
	HighAcc sum = { 0 };
	int tmp;
	int i, j;

	if (a.len == 1 && a.data[0] == 0 || b.len == 1 && b.data[0] == 0)
	{
		sum.len = 1;
		return sum;
	}

	for (i = 0; i < a.len; i++)
	{
		for (j = 0; j < b.len; j++)
		{
			tmp = a.data[i] * b.data[j] + sum.data[i + j];
			sum.data[i + j] = tmp % 10;
			sum.data[i + j + 1] += tmp / 10;
		}
	}
	sum.len = a.len + b.len - !sum.data[a.len + b.len - 1];
	return sum;
}

HighAcc add(HighAcc a, HighAcc b)
{
	HighAcc sum = { 0 };
	int tmp;
	int i;
	int maxlen = a.len > b.len ? a.len : b.len;

	for (i = 0; i < maxlen; i++)
	{
		tmp = a.data[i] + b.data[i] + sum.data[i];
		sum.data[i] = tmp % 10;
		sum.data[i + 1] = tmp / 10;
	}
	sum.len = maxlen + sum.data[maxlen];
	return sum;
}

void dealNumber(HighAcc * h)
{
	int i = 0, j = strlen(h->data) - 1;
	char tmp;

	h->len = j + 1;
	for (; i <= j; i++, j--)
	{
		tmp = h->data[i];
		h->data[i] = h->data[j] - '0';
		h->data[j] = tmp - '0';
	}
}

void printNumber(HighAcc h)
{
	int i;
	for (i = h.len - 1; i >= 0; i--)
	{
		putchar(h.data[i] + '0');
	}
}

int main()
{
	HighAcc a = { 0 };
	HighAcc b = { 0 };
	HighAcc sum;
	int i;

	scanf("%s%s", a.data, b.data);
	dealNumber(&a);
	dealNumber(&b);

	sum = mul(a, b);

	printNumber(sum);
	putchar('\n');

	return 0;
}