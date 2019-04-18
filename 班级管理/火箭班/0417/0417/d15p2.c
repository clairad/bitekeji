#include <stdio.h>

int main()
{
	int i;
	int sum = 0;

	for (i = 20; i > 1; i /= 2)
	{
		sum += i - i % 2;
		i += i % 2;
	}
	printf("%d", sum + 1);
	return 0;
}