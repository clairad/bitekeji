#include <stdio.h>

int main()
{
	int i, j;
	int year = 1900;
	
	int n = 9;

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= i; j++)
		{
			printf("%d*%d=%d ", j, i, i * j);
		}
		printf("\n");
	}

	//if ((year % 100 != 0 && year % 4 == 0) || year % 400 == 0)

	return 0;
}