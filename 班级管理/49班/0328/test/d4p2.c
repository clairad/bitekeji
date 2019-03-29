#include <stdio.h>
#include <string.h>

int main2()
{
	int n;
	int i;
	int a, b, c;

	for (i = 100; i <= 999; i++)
	{
		a = i / 100;
		b = i / 10 % 10;
		c = i % 10;
		n = a * a * a + b * b * b + c * c * c;
		if (n == i)
		{
			printf("%d\n", i);
		}
	}

	system("pause");
	return 0;
}