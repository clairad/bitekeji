#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main51()
{
	srand((unsigned int)time(NULL));
	int ran = rand() % 100 + 1;
	int guess;
	while (1)
	{
		scanf("%d", &guess);
		while('\n' != getchar());
		if (guess == ran)
		{
			printf("It has been found.\n");
			break;
		}
		else if (guess > ran)
		{
			printf("It is bigger than ran.\n");
		}
		else
		{
			printf("It is smaller than ran.\n");
		}
	}
	return 0;
}