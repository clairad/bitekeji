#include <stdio.h>

int i;
int m()
{
	i--;

	int j = sizeof(i);
	if (i > j)
	{
		printf(">");
	}
	else
	{
		printf("<");
	}
	return 0;
}