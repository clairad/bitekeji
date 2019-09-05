#include <stdio.h>

int main()
{
	const int i = 2;
	
	*((int *)&i) = 4;
	
	printf("%d", i);
	return 0;
} 
