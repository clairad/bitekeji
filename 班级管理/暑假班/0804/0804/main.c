#include <stdio.h>
#include <math.h>

int d2p1()
{
	int a = 5, b = 10;
	int tmp;
#if 0
	tmp = a;
	a = b;
	b = tmp;
#elif 0
	a = a + b;
	b = a - b;
	a = a - b;
#else
	a ^= b;
	b ^= a;
	a ^= b;
#endif

	printf("a = %d, b = %d\n", a, b);
	 	return 0;
}

int d2p3()
{
	int arr[10] = { 8, 4, 7, 0, -1, 9, 2, -3, 3, 1 };
	int max = 0x80000000;
	int sec = 0x80000000;
	int i;

	for (i = 0; i < 10; i++)
	{
		if (max < arr[i])
		{
			sec = max;
			max = arr[i];
		}
		else if (sec < arr[i])
		{
			sec = arr[i];
		}
	}

	printf("%d", sec);
	return 0;
}

int d2p4()
{
	int a, b, c;

	scanf("%d%d%d", &a, &b, &c);

	if (a > b)
	{
		if (b > c)
		{
			printf("%d %d %d\n", a, b, c);
		}
		else if (a > c)
		{
			printf("%d %d %d\n", a, c, b);
		}
		else
		{
			printf("%d %d %d\n", c, a, b);
		}
	}
	else
	{
		if (b < c)
		{
			printf("%d %d %d\n", c, b, a);
		}
		else if (a < c)
		{
			printf("%d %d %d\n", b, c, a);
		}
		else
		{
			printf("%d %d %d\n", b, a, c);
		}
	}

	return 0;
}


int d2p5()
{
	int a, b;

	scanf("%d%d", &a, &b);
#if 0
	int smaller = a < b ? a : b;

	int i;
	int max = 0;

	for (i = 1; i <= smaller; i++)
	{
		if (a % i == 0 && b % i == 0)
		{
			max = i;
		}
	}

	if (max == 1)
	{
		printf("两数互质\n");
		return 0;
	}
	printf("%d和%d的最大公约数为%d", a, b, max);

#else
	int c;

	while (c = a % b)
	{
		a = b;
		b = c;
	}

	printf("%d", b);
#endif

	return 0;
}

int d3p1()
{
	int a[5] = { 1, 2, 3, 4, 5 };
	int b[5] = { 5, 4, 3, 2, 1 };
	int i;

	printf("a数组：");
	for (i = 0; i < 5; i++)
	{
		printf("%d ", a[i]);
	}
	putchar('\n');

	printf("b数组：");
	for (i = 0; i < 5; i++)
	{
		printf("%d ", b[i]);
	}
	putchar('\n');


	for (i = 0; i < 5; i++)
	{
		int tmp;

		tmp = a[i];
		a[i] = b[i];
		b[i] = tmp;
	}


	printf("a数组：");
	for (i = 0; i < 5; i++)
	{
		printf("%d ", a[i]);
	}
	putchar('\n');

	printf("b数组：");
	for (i = 0; i < 5; i++)
	{
		printf("%d ", b[i]);
	}
	putchar('\n');

	return 0;
}

int d3p2()
{
	int i, flag = 1;
	double tmp = 1, sum = 0;

	for (i = 1; i <= 100; i++)
	{
		tmp = flag * 1.0 / i;
		sum += tmp;
		flag *= -1;
	}

	printf("%lf\n", sum);
	return 0;
}

int d3p3()
{
	int i;
	int count = 0;

	for (i = 1; i < 100; i++)
	{
		if (i % 10 == 9)
		{
			count++;
		}

		if (i / 10 == 9)
		{
			count++;
		}
	}

	printf("%d\n", count);
	return 0;
}

int d1p1()
{
	int n;
	int tmp;
	int i;

	for (n = 2; n <= 10000000; n++)
	{ 
		tmp = sqrt(n);
		for (i = 2; i <= tmp; i++)
		{
			if (n % i == 0)
			{
				break;
			}
		}
		if (i == tmp + 1)
		{ 
			printf("%d\n", n);
		}
	}
	return 0;
}

int d1p3()
{
	int i;

	for (i = 1000; i <= 2000; i++)
	{
		if (i % 400 == 0 ||
			(i % 100 != 0 && i % 4 == 0))
		{
			printf("%d\n", i);
		}
	}

	return 0;
}

int d1p2()
{
	int n = 9;
	int i, j;

	//scanf("%d", &n);

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= i; j++)
		{
			printf("%d*%d=%d ", j, i, i * j);
		}
		putchar('\n');
	}

	return 0;
}

int main()
{
	int n;
	int i, j;

	scanf("%d", &n);

	for (i = 1; i <= n; i++)
	{
#if 0
		for (j = 1; j <= n - i; j++)
		{
			putchar(' ');
		}

		for (j = 1; j <= 2 * i - 1; j++)
		{
			putchar('*');
		}
#endif
		for (j = 1; j <= n + i - 1; j++)
		{
			putchar(j <= n - i ? ' ' : '*');
		}
		putchar('\n');
	}

	return 0;
}