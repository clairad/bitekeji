#include <stdio.h>
#include <string.h>

int d15p1()
{
	int sum = 0;
	int arr[10] = { 1, 2, 3, 2, 4, 6, 1, 8, 3, 4 };

	int i;
	for (i = 0; i < 10; i++)
	{
		sum ^= arr[i];
	}

	int n = -1;
	for (i = 0; i < 32; i++)
	{
		if (sum >> i & 1)
		{
			n = i;
			break;
		}
	}

	int sum1 = 0, sum2 = 0;

	for (i = 0; i < 10; i++)
	{
		if (arr[i] >> n & 1)
		{
			sum1 ^= arr[i];
		}
		else
		{
			sum2 ^= arr[i];
		}
	}

	printf("%d %d\n", sum1, sum2);

	return 0;
}

int d15p2()
{
	int n = 20;
	int sum = 0;
	int ex = 0;
	int i;

	for (i = n; i > 0; i /= 2)
	{
		sum += i;
		i += ex;
		ex = i % 2;
	}

	printf("%d\n", sum);
	return 0;
}

int extra()
{
	char str[] = "bi,te.ke-ji";

	puts(strpbrk(str, ",.-"));

	puts(strtok(str, ",.-"));
	puts(strtok(NULL, ",.-"));
	puts(strtok(NULL, ",.-"));
	puts(strtok(NULL, ",.-"));

	return 0;
}

int num;
int countnum(int n)
{
	num++;
	int i;
	for (i = 1; i <= n / 2; i++)
	{
		countnum(i);
	}
	return num;
}

int luogu1028()
{
	int n = 7;
	int a[1002] = { 0 };

	a[1] = 1;

	int i;
	for (i = 2; i <= n; i += 2)
	{
		a[i + 1] = a[i] = a[i - 1] + a[i / 2];
	}
	
	printf("%d", a[n]);
	return 0;
}

void choosenum(int *src, int n, int k, int res, int start)
{
	if (k <= 0)
	{
		printf("%d\n", res);
		return;
	}

	int i;
	for (i = start; i <= n - k; i++)
	{
		choosenum(src, n, k - 1, res + src[i], i + 1);
	}
}

int main()
{
	int a[20] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	int n = 8, k = 4;

	choosenum(a, n, k, 0, 0);

	return 0;
}