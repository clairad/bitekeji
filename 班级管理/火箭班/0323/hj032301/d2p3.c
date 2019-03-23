#include <stdio.h>

int main4()
{
	int i;
	int max, next;
	int tmp;
	int first = 1;

	scanf("%d%d", &max, &next);
	if (next > max)
	{
		tmp = max;
		max = next;
		next = tmp;
	}

#define TEST
#ifdef TEST
	scanf("%d", &tmp);
	if (tmp > max)
	{
		printf("%d %d %d\n", tmp, max, next);
	}
	else if (tmp > next)
	{
		printf("%d %d %d\n", max, tmp, next);
	}
	else
	{
		printf("%d %d %d\n", max, next, tmp);
	}
#else

	for (i = 2; i < 10; i++)
	{
		scanf("%d", &tmp);
		/*
		if (first)
		{
			max = tmp;
			first = 0;
			continue;
		}*/
		if (tmp > max)
		{
			next = max;
			max = tmp;
		}
		else if (tmp > next)
		{
			next = tmp;
		}
	}

	printf("max = %d, next = %d\n", max, next);
#endif
	system("pause");
	return 0;
}