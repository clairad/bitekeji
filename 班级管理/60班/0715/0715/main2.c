#include <stdio.h>

int __main()
{
	//迭代法

	int m = 1;
	int n = 7;
	int i, sum = 0, tmp = 0;

	for (i = 0; i < n; i++)
	{
		tmp = tmp * 10 + m;
		sum += tmp;
	}
	printf("%d", sum);
	return 0;
}

int main3()
{
	int n;
	int sum = 0;
	int i;
	int m;
	scanf("%d%d", &n, &m);

	for (i = n; i; i /= m)
	{
		sum = sum * m + i % m;
	}

	if (sum == n)
	{
		printf("%d在%d进制下是回文数\n", n, m);
	}
	else
	{
		printf("%d在%d进制下不是回文数\n", n, m);
	}

	return 0;
}

int main()
{
	int i, j, n;
	int week[7] = { 0 };
	int emday[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int sum = 13;
	scanf("%d", &n);
	for (i = 1900; i < 1900 + n; i++)
	{
		for (j = 0; j < 12; j++)
		{
			week[sum % 7]++;
			sum += emday[j];
			if (j == 2 && (i % 400 == 0 || i % 4 == 0 && i % 100 != 0))
			{
				sum++;
			}
		}
	}

	for (i = 0; i < 7; i++)
	{
		printf("%d ", week[i]);
	}
}