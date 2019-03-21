#include <stdio.h>
#include <math.h>

int main5()
{
	int i, j;
	int sum = 0, count = 0;
	int tmp[10] = { 0 };

	for (i = 0; i <= 100000000; i++)
	{ 
		for (j = i; j; j /= 10) //ÊýÎ»±éÀú
		{
			tmp[count] = j % 10;
			count++;
		}

		for (j = 0; j < count; j++)
		{
			sum += pow(tmp[j], count);
		}

		if (i == sum)
		{
			printf("%d\n", i);
		}

		sum = count = 0;
	}


	system("pause");
	return 0;
}