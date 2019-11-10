#include <stdio.h>

int d4p3()
{
	int i;
	int n, m;
	scanf("%d%d", &n, &m);

	int sum = 0;
	int tmp = 0;
	for (i = 1; i <= m; i++)
	{
		tmp = tmp * 10 + n;
		sum += tmp;
	}

	printf("%d\n", sum);
	return 0;
}