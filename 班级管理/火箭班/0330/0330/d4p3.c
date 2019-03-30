#include <stdio.h>

int main43()
{
	int tmp = 0, sum = 0;
	int i;
	int n;
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