#include <stdio.h>
#include <math.h>

int d4p2p1()
{
	int n, m;
	scanf("%d%d", &n, &m);

	int i, sum = 0;
	for (i = n; i; i /= m) //数位遍历：1、取出输出的每一位；2、进制转换
	//i % m能完成对数字n在m进制下每一位的遍历
	{
		sum = sum * m + i % m;
	}

	if (sum == n)
	{
		printf("是回文数\n");
	}
	else
	{
		printf("不是回文数\n");
	}
	return 0;
}

int d4p2p2()
{
	int i, j, sum = 0;
	int n = 1;
	int flag = 10;

	for (i = 0; i < 100000000; i++)
	{
		if (i == flag)
		{
			n++;
			flag *= 10;
		}

		for (j = i; j; j /= 10)
		{
			sum += pow(j % 10, n);
		}

		if (sum == i)
		{
			printf("%d\n", i);
		}
		sum = 0;
	}

	return 0;
}

int d4p2()
{
	int i;
	int tmp;
	for (i = 100; i < 1000; i++)
	{
		tmp = pow(i % 10     , 3) +
			  pow(i / 10 % 10, 3) +
			  pow(i / 100    , 3);
		if (tmp == i)
		{
			printf("%d\n", i);
		}
	}

	return 0;
}