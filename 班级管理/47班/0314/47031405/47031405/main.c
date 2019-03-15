#include <stdio.h>
#include <Windows.h>

int main()
{
	int i, sum = 0, tmp = 0, m, n;
	/*
	for (i = 1; i <= 100; i++)
	{
		sum += i;
	}*/
	/*
	for (i = 1; i <= 10; i++)
	{
		tmp *= i;
		sum += tmp;
	}*/

	for (i = 1; i <= n; i++)
	{
		tmp = tmp * 10 + m;
		sum += tmp;
	}
	/*ACM
	m = 4 n = 3
		4 + 44 + 444
	m = 2 n = 5
		2 + 22 + 222 + 2222 + 22222*/

	printf("%d\n", sum);
	system("pause");
	return 0;
}