#include <stdio.h>

int main7()
{
	int i = 0;
	double sum = 0;
	double tmp = 1;
	int flag = 1;

	for (i = 1; i <= 100; i++)
	{
		tmp = 1.0 / i * flag;//(i % 2 ? 1 : -1);
		sum += tmp;
		flag *= -1;
	}

	printf("%lf\n", sum);
	system("pause");
	return 0;
}