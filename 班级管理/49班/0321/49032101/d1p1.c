#include <stdio.h>
#include <math.h>

int _main()
{
	int i;
	int n;
	int flag = 0;
	int tmp;
	
	for (n = 2; n <= 100000000; n++)
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
			printf("%d\n", n);
		}
		flag = 0;
	}


	system("pause");
	return 0;
}