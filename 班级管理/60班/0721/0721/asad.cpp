#include <stdio.h>

int main()
{
	int a[8] = {1,2,3,4,5,6,7,8};
	int i;
	
	for(i = 0; i < 8; i++)
	{
		printf("%d", *(a + i));
	}
	
	return 0;
}

