#include <stdio.h>
#include <math.h>

int __main()
{
	int i, n;
	int sum = 0, tmp = 0;

	scanf("%d", &n);

	for (i = 0; i < 5; i++)
	{
		tmp = tmp * 10 + n;
		sum += tmp;
	}

	printf("%d\n", sum);
	system("pause");
	return 0;
}