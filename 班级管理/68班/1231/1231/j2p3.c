#include <stdio.h>
#include <string.h>

int strRoundStr(char * src, char * find)
{
	char tmp[256] = { 0 };

	strcpy(tmp, src);
	strcat(tmp, src);
	return strstr(tmp, find) != NULL;
}

int j2p3()
{
	char src[] = "ABCDEFG";

	char find[] = "GAA";

	printf("%d", strRoundStr(src, find));
	return 0;
}