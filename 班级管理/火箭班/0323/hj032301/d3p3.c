#include <stdio.h>

int main()
{
	int i = 0;
	int count = 0;

	for (i = 1; i <= 1000; i++)
	{
		if (i % 10 == 9)
		{
			count++;
		}
		if (i / 10 % 10 == 9)
		{
			count++;
		}
		if (i / 100 == 9)
		{
			count++;
		}
	}

	printf("%d\n", count);

	system("pause");
	return 0;
}