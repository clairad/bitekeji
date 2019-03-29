#include <stdio.h>
#include <string.h>

int main2p()
{
	int n;
	int sn;
	int i;
	int tmp, sum = 0;

	scanf("%d%d", &n, &sn);

	for (i = n; i; i /= sn)
	{
		tmp = i % sn;
		sum = sum * sn + tmp;
	}

	if (n == sum)
	{
		printf("%d在%d进制下是回文数\n", n, sn);
	}
	else
	{
		printf("%d在%d进制下不是回文数\n", n, sn);
	}

	system("pause");
	return 0;
}