#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int mainroll()
{
	srand((unsigned int)time(NULL));

	printf("%d≈≈%d¡–\n", rand() % 7 + 1, rand() % 12 + 1);
	return 0;
}