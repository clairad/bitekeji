#include <iostream>
using namespace std;

/*void InsertSort(int * src, int n)
{
	int i, j;
	int tmp;

	for (i = 1; i < n; i++)
	{
		tmp = src[i];

		for (j = i; j > 0 && src[j - 1] > tmp; j--)
		{
			src[j] = src[j - 1];
		}

		src[j] = tmp;
	}
}*/

void InsertSort(float * src, int n)
{
	int i, j;
	float tmp;

	for (i = 1; i < n; i++)
	{
		tmp = src[i];

		for (j = i; j > 0 && src[j - 1] > tmp; j--)
		{
			src[j] = src[j - 1];
		}

		src[j] = tmp;
	}
}

bool cmpnum(int a, int b)
{
	return a < b;
}

void InsertSort(int * src, int n, bool (*cmp)(int , int) = cmpnum)
{
	int i, j;
	int tmp;

	for (i = 1; i < n; i++)
	{
		tmp = src[i];

		for (j = i; j > 0 && cmp(tmp, src[j - 1]); j--)
		{
			src[j] = src[j - 1];
		}

		src[j] = tmp;
	}
}

void sort(int * src, int n, int flag = 0)
{
	switch (flag)
	{
	case 0:
		InsertSort(src, n);
		break;
	case 1:
		break;
	case 2:
		break;
	default:;
	}
}

bool cmpwaytest(int a, int b)
{
	return a > b;
}

int _main()
{
	int a[5] = { 5, 1, 4, 2, 3 };
	float f[5] = { 8.2, 1.7, 3.5, 2.6, 4.8 };

	InsertSort(a, 5, cmpwaytest);
	InsertSort(f, 5);

	for (auto i : a)
	{
		cout << i << endl;
	}

	for (auto i : f)
	{
		cout << i << endl;
	}

	return 0;
}


/*
1、写一个排序函数接口，能完成对整数和小数的排序。
2、接口中多传入一个缺省参数，如果不指定，就采用A排序方式，如果指定了，就按他的选择决定排序方式（至少包含三种）。
3、在上述的基础上，完成对结构体的排序。通过传入判断大小的函数来实现。
*/