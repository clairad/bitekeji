#include <stdio.h>
//#define ALL

int main2()
{
	int n, i, max, next, tmp;

	scanf("%d%d", &max, &next);
	if (next > max)
	{
		tmp = next;
		next = max;
		max = tmp;
	}

#if 0
	for (i = 2; i < 10; i++)
	{
		scanf("%d", &n);
		if (max < n)
		{
			next = max;
			max = n;
		}
		else if (next < n)
		{
			next = n;
		}
	}
	
	printf("最大:%d，次大:%d\n", max, next);
#else
	scanf("%d", &tmp);
	if (max < tmp)
	{
		printf("%d，%d, %d\n", tmp, max, next);
	}
	else if (next < tmp)
	{
		printf("%d，%d, %d\n", max, tmp, next);
	}
	else
	{ 
		printf("%d，%d, %d\n", max, next, tmp);
	}
#endif
	system("pause");
	return 0;
}