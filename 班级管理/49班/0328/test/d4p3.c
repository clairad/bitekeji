#include <stdio.h>
#include <string.h>

int main3()
{
	int n;
	int i;
	int tmp = 0, sum = 0;

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