#include <stdio.h>

int divide(int a, int b, int * pres)
{
	if (b == 0)
	{
		return 0;
	}
	*pres =  a / b;
	return 1;
}

int swapArgs(int *pa, int *pb)
{
	int tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}

int main62()
{
	int a = 17, b = 3;
	swapArgs(&a, &b);
	/*
	int res;

	if (divide(a, b, &res))
	{
		printf("%d/%d=%d\n", a, b, res);
	}
	else
	{
		printf("³ıÊıÎªÁã\n");
	}*/
	printf("a = %d, b = %d\n", a, b);
	system("pause");
	return 0;
}