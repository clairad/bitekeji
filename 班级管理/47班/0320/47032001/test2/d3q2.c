#include <stdio.h>

int main1()
{
	int i;
	double sum = 0, tmp, flag = 1;

	for (i = 1; i <= 100; i++)
	{
		tmp = 1.0 / i * (i % 2 ? 1 : -1);
		sum += tmp;
		//flag *= -1;
	}

	printf("%lf\n", sum);
	system("pause");
	return 0;
}