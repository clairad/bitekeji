#include <stdio.h>
/*
for循环就是干遍历的活的
1、数字遍历
for(i = a; i < b; i++)
i完成了对数字[a,b)之间的遍历

2、数组遍历
for(i = 0; i < n; i++)
a[i]完成了对数组a的遍历

3、数位遍历
for(i = n; i; i /= m)
i % m完成在m进制下对n每一位的遍历

4、字符串遍历
for(i = 0; str[i]; i++)
str[i]完成了对字符串str的遍历

5、链表遍历
for(cur = head; cur; cur = cur->next)
cur完成了对链表head的遍历

6、容器遍历
for(iter = v.begin(); iter != v.end(); iter++)
迭代器iter完成了对容器v的遍历

*/

void printNum(int n, int m)
{
	if (n > 0)
	{ 
		printNum(n / m, m);
		putchar("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"[n % m]);
	}
}

int T1()
{
	int n = 310879183;

	/*int i;
	for (i = n; i; i /= 16)
	{
		printf("%d ", i % 16);
	}*/
	printNum(n, 16);
	return 0;
}

int conutOneEasy(int n)
{
	int count = 0;

	int i;
	for (i = n; i; i /= 2)
	{
		count += i % 2;
	}
	return count;
}

int conutOneNormal(int n)
{
	int count = 0;

	while (n)
	{
		n &= n - 1;
		count++;
	}
	return count;
}

int conutOne(int n)
{
	n = (n & 0x55555555) + (n >> 1 & 0x55555555);
	n = (n & 0x33333333) + (n >> 2 & 0x33333333);
	n = (n & 0x0f0f0f0f) + (n >> 4 & 0x0f0f0f0f);
	n = (n & 0x00ff00ff) + (n >> 8 & 0x00ff00ff);
	n = (n & 0x0000ffff) + (n >> 16 & 0x0000ffff);

	return n;
}

int main()
{
	int n = 310879183;
	

	printf("%d", conutOne(n));
	return 0;
}