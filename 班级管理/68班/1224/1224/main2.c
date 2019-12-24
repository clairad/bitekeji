#include <stdio.h>
#include <stdlib.h>

int main()
{
	int * pi = (int *)malloc(6 * sizeof(int));
	pi[2] = 4;
	pi[4] = 8;
	pi[5] = 9;

	printArray(pi, 6);

	free(pi);

	printArray(pi, 6);
	return 0;
}