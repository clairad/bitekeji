#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int find(char * a, char * b)
{
	char * tmp = (char *)calloc(strlen(a) * 2 + 1, sizeof(char));
	if (tmp == NULL)
	{
		return 0;
	}

	strcpy(tmp, a);
	strcat(tmp, a);

	if (strstr(tmp, b))
	{
		free(tmp);
		return 1;
	}
	free(tmp);
	return 0;
}

int main142()
{
	char a[] = "AABCD";
	char b[] = "BCDAA";

	if (find(a, b))
	{
		printf("找到了\n");
	}
	else
	{
		printf("没找到\n");
	}

	return 0;
}