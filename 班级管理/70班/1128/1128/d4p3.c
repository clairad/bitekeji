#include <stdio.h>

int d4p3()
{
	int n, m;
	scanf("%d%d", &m, &n);

	int i;
	int tmp = 0, sum = 0;
	for (i = 0; i < n; i++)
	{
		tmp = tmp * 10 + m;
		sum += tmp;
	}

	printf("%d", sum);
	return 0;
}