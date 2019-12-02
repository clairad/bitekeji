#include <stdio.h>

int main()
{
	char str[60];
	
	scanf("%[^a]", str);
	
	printf("%s", str);
	return 0;
} 
