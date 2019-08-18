#include <stdio.h>
#include <string.h>

int d10p3()
{
	int n = 3716;

	int i;
	for (i = n; i; i /= 8)
	{
		printf("%d\n", i % 8);
	}

	return 0;
}

int extra()
{
	int i;
	int m = 4, n = 2;
	int tmp = 0;
	int sum = 0;
	/*
	for (i = 1; i <= 10; i++)
	{
		tmp *= i;
		sum += tmp;
	}*/
	/*n = 2
	m = 4
	2+22+222+2222*/

	for (i = 0; i < m; i++)
	{
		tmp = tmp * 10 + n;
		sum += tmp;
	}
	printf("%d", sum);
	return 0;
}

int extra2()
{
	int n = 1234;
	int m = 8;
	int tmp, sum = 0;

	int i;
	for (i = n; i; i /= m)
	{
		tmp = i % m;
		sum = sum * m + tmp;
	}

	printf("%d", sum);
	return 0;
}

int d10p1()
{
	int n = 1000;
	int count = 0;

	while (n)
	{
		count++;
		n &= n - 1;
	}

	printf("%d", count);
	return 0;
}

int d10p2()
{
	int n = 2019;

	int sum1 = 0, sum2 = 0;
	int len1 = 0, len2 = 0;

	int count = 1;
	int i;
	for (i = n; i; i >>= 1)
	{
		if (count & 1)
		{
			sum1 |= (i & 1) << len1;
			len1++;
		}
		else
		{
			sum2 |= (i & 1) << len2;
			len2++;
		}
		count++;
	}

	for (i = len1 - 1; i >= 0; i--)
	{
		printf("%d", sum1 >> i & 1);
	}
	putchar('\n');

	for (i = len2 - 1; i >= 0; i--)
	{
		printf("%d", sum2 >> i & 1);
	}
	putchar('\n');
	//printf("%d %d\n", sum1, sum2);
	//printf("%d %d\n", len1, len2);
	return 0;
}

int d12p1()
{
	unsigned int n = 25;
	unsigned int sum = 0;

	int i;
	for (i = 0; i < 32; i++, n /= 2)
	{
		sum = sum * 2 + n % 2;
	}

	printf("%u", sum);
	return 0;
}

int d12p3()
{
	int a[9] = { 6, 2, 5, 5, 8, 2, 3, 6, 3 };
	int sum = 0;

	int i;
	for (i = 0; i < 9; i++)
	{
		sum ^= a[i];
	}

	printf("%d", sum);
	return 0;
}

void reverse(char * start, char * end)
{
	char tmp;
	while (start < end)
	{
		tmp = *start;
		*start = *end;
		*end = tmp;

		start++;
		end--;
	}
}

void reverseString(char * src)
{
	int i;
	char * start = src;
	char * end;
	for (i = 0; src[i]; i++)
	{
		if (src[i] == ' ')
		{
			end = src + i - 1;
			reverse(start, end);
			start = src + i + 1;
		}
	}
	end = src + i - 1;
	reverse(start, end);
	reverse(src, end);
}

void reverseStringS(char * src)
{
	char * tmp;
	char dest[100] = { 0 };

	while (tmp = strrchr(src, ' '))
	{
		strcat(dest, tmp + 1);
		strcat(dest, " ");
		*tmp = 0;
	}
	strcat(dest, src);
	strcpy(src, dest);
}

int d12p4()
{
	char str[] = "sing dance rap basketball";

	reverseStringS(str);

	puts(str);

	return 0;
}

/*
sum |= 1 << n;
sum &= ~(1 << n);
sum ^= 1 << n;
*/

int printArray(int * arr, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	putchar('\n');
}

int d13p1()
{
	int a[8] = { 1, 1, 3, 3, 5, 5, 7, 7 };
	int size = 8;
	int * front = a;
	int * end = a + size - 1;
	int tmp;

	while (*front % 2 && front - a < size)
	{
		front++;
	}

	while (!(*end % 2) && end >= a)
	{
		end--;
	}
	
	while (front < end)
	{
		tmp = *front;
		*front = *end;
		*end = tmp;

		while (*front % 2)
		{
			front++;
		}

		while (!(*end % 2))
		{
			end--;
		}
	}

	printArray(a, size);
	return 0;
}

int find(int a[][3], int n, int find)
{
	int i = 0, j = n - 1;
	while (j >= 0 && i < n)
	{
		if (a[i][j] > find)
		{
			j--;
		}
		else if (a[i][j] < find)
		{
			i++;
		}
		else
		{
			return 1;
		}
	}
	return 0;
}

int d13p2()
{
	int a[3][3] = {
		{1, 3, 5},
		{3, 5, 7},
		{5, 7, 9}
	};

	printf("%d\n", find(a, 3, 7));

	return 0;
}

int leftTrun(char *str, int n, int m)
{
	m %= n;
	int end = strlen(str);

	reverse(str, str + m - 1);
	reverse(str + m, str + end - 1);
	reverse(str, str + end - 1);
}

int main()
{
	char str[] = "ABCDE";
	leftTrun(str, 5, 102);
	puts(str);
	return 0;
}