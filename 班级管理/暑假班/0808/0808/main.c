#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define PWDCHECK 3

void d4p1(int n)
{
	int i, j;

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n - i; j++)
		{
			putchar(' ');
		}

		for (j = 1; j <= 2 * i - 1; j++)
		{
			putchar('*');
		}
		putchar('\n');
	}

	for (i = n - 1; i > 0; i--)
	{
		for (j = 1; j <= n - i; j++)
		{
			putchar(' ');
		}

		for (j = 1; j <= 2 * i - 1; j++)
		{
			putchar('*');
		}
		putchar('\n');
	}
}

void d4p2m()
{
	int i;
	int a, b, c;
	int sum;

	for (i = 100; i <= 999; i++)
	{
		a = i % 10;
		b = i / 10 % 10;
		c = i / 100;

		sum = pow(a, 3) + pow(b, 3) + pow(c, 3);

		if (sum == i)
		{ 
			printf("%d\n", sum);
		}
	}
}

void d4p2(int n)
{
	int i, j;
	//int tmp;
	int sum = 0;
	int m = 1;
	int flag = 10;

	for (i = 0; i < n; i++)
	{
		if (flag == i)
		{
			m++;
			flag *= 10;
		}

		for (j = i; j; j /= 10)
		{
			sum += pow(j % 10, m);
		}

		if (sum == i)
		{
			printf("%d\n", sum);
		}
		sum = 0;
	}
}

int d4p3(int m, int n)
{
	int i;
	int tmp = 0, sum = 0;

	for (i = 0; i < n; i++)
	{
		tmp = tmp * 10 + m;
		sum += tmp;
	}

	return sum;
}

int d5p2(int * arr, int n, int f)
{
	int mid;
	int start = 0, end = n - 1;

	while (start <= end)
	{ 
		mid = (start + end) / 2;
		if (f < arr[mid])
		{
			end = mid - 1;
		}
		else if (f > arr[mid])
		{
			start = mid + 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}

int d5p3(char * src)
{
	int i;
	

	if (strcmp(src, "cxkjntm") == 0)
	{
		return 1;
	}
	return 0;
}

int isSmallLetter(char ch)
{
	return ch >= 'a' && ch <= 'z';
}

void d5p4()
{
	char ch;
	while (1)
	{
		ch = getchar();
		if (ch >= 'A' && ch <= 'Z')
		{
			ch += 'a' - 'A';
		}
		else if (isSmallLetter(ch))
		{
			ch -= 'a' - 'A';
		}
		else if (isdigit(ch))
		{
			continue;
		}
		else if (ch == '#')
		{
			break;
		}

		putchar(ch);
	}
}

void d6p1(int n)
{
	int i, j;

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= i; j++)
		{
			printf("%d*%d=%d ", j, i, i * j);
		}
		putchar('\n');
	}
}

void swapArgs(int *pa, int *pb)
{
	int tmp;

	tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}

int isLeapYear(int year)
{
	return year % 400 == 0 ||
		  (year % 4 == 0 && year % 100 != 0);
}

void initArray(int * dst, int * src, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		dst[i] = src[i];
	}
}

void emptyArray(int * dst, int n)
{
	memset(dst, 0, sizeof(int) * n);
	//清谁，清成啥，清多长
}

void reverseArray(int * dst, int n)
{
	int i, j;
	
	for (i = 0, j = n - 1; i < j; i++, j--)
	{
		swapArgs(dst + i, dst + j);
	}
}

void printArray(int * dst, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		printf("%d ", dst[i]);
	}
	putchar('\n');
}

int isPrimeNumber(int n)
{
	int tmp, i;

	tmp = sqrt(n);
	for (i = 2; i <= tmp; i++)
	{
		if (n % i == 0)
		{
			return 0;
		}
	}
	return 1;
}

int _main()
{
	//d4p1(6);
	//d4p2m();
	//d4p2(100000000);
	//int res = d4p3(2, 5);
	//printf("%d\n", res);
	//int arr[10] = { 2, 5, 7, 9, 11, 14, 16, 20, 22, 31 };
	//printf("%d\n", d5p2(arr, 10, 20));
	/*int i;
	char str[64] = { 0 };
	for (i = 0; i < PWDCHECK; i++)
	{
		scanf("%s", str);
		if (1 == d5p3(str))
		{
			printf("密码正确\n");
			break;
		}
		else
		{
			printf("密码错误\n");
		}
	}
	if (i == PWDCHECK)
	{
		printf("退出\n");
		return 1;
	}*/

	//d5p4();
	//d6p1(4);
	/*
	int a = 4, b = 5;
	swapArgs(&a, &b);
	printf("a = %d, b = %d\n", a, b);
	*/

	//int a[5] = { 1, 2, 3, 4, 5 };

	//printf("%d\n", 3[a]);

	/*int src[9];
	int dst[9] = { 2, 5, 4, 9, 8, 6, 7, 1, 3 };

	initArray(src, dst, 9);
	printArray(src, 9);
	reverseArray(src, 9);
	printArray(src, 9);
	emptyArray(src, 9);
	printArray(src, 9);*/

	int n;

	for (n = 2; n <= 10000000; n++)
	{
		if (isPrimeNumber(n))
		{
			printf("%d\n", n);
		}
	}
	return 0;
}

/*
1、可以重复利用代码
2、可以增强代码的可读性
3、可以增强代码的可移植性
4、方便开发和维护
*/