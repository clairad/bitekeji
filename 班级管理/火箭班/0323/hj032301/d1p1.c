#include <stdio.h>
#include <math.h>

int main1()
{
	int i;
	int tmp;
	int n;
	int flag = 0;

	for (n = 2147480000; n < 2147483647; n++)
	{ 
		tmp = sqrt(n);
		for (i = 2; i <= tmp; i++)
		{
			if (n % i == 0)
			{
				flag = 1;
				break;
			}
		}

		if (flag == 0)
		{ 
			printf("%dÊÇÖÊÊý\n", n);
		}
		flag = 0;
	}
	system("pause");
	return 0;
}