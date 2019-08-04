#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int a = 1000000;
	
	srand((unsigned)time(NULL));
	
	printf("int src[] = {\n");
	
	for(int i = 0; i < a; i++)
	{
		printf("%d, ", rand() % 30000);
	}
	
	printf("};");
	
	return 0;
}
