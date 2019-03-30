#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

int main1()
{
	srand((unsigned int)time(NULL));
	int r = rand() % 100;
	int n = -1;

	while (n != r)
	{
		while (!scanf("%d", &n))
		{
			getchar();
		}
		if (n > r)
		{
			printf("猜大了\n");
		}
		else if (n < r)
		{
			printf("猜小了\n");
		}
	}
	printf("猜对了\n");

	system("pause");
	return 0;
}