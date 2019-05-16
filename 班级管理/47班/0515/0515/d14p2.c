#include <stdio.h>
#include <string.h>

int find_round(char * src, char * find)
{
	char tmp[256] = { 0 };
	strcpy(tmp, src);
	strcat(tmp, src);
	return strstr(tmp, find) ? 1 : 0;
}

int main142()
{
	printf("%d\n", find_round("ABCDE", "DDABC"));

	return 0;
}