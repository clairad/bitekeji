#include <stdio.h>
#include <math.h>

int main()
{
	int i, flag = 0, tmp, k;
	
	for (k = 100; k <= 200; k++)
	{ 
		tmp = sqrt(k);
		for (i = 2; i <= tmp; i++)
		{
			if (k % i == 0)
			{
				flag = 1;
				break;
			}
		}
		if (flag == 0)
		{ 
			printf("%d\n", k);
		}
		flag = 0;
	}
	return 0;
}