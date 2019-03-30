#include <stdio.h>
#include <math.h>

int main42()
{
	int i, j;
	int count = 0, sum = 0;
	char a[10] = { 0 };

	for (i = 0; i < 100000000; i++)
	{ 
		for (j = i; j; j /= 10)
		{
			a[count] = j % 10;
			count++;
		}

		for (j = 0; j < count; j++)
		{
			sum += pow(a[j], count);
		}

		if (sum == i)
		{
			printf("%d\n", i);
		}
		count = sum = 0;
	}
	system("pause");
	return 0;
}