#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int round(char s[], int k)
{
	int len = strlen(s);
	char * tmp = (char *)calloc(len + 1, sizeof(char));
	if (tmp == NULL)
	{
		return 1;
	}
	int i;
	k %= len;
	for (i = 0; i < len - k; i++)
	{
		tmp[i] = s[i + k];
	}

	for (; i < len; i++)
	{
		tmp[i] = s[i + k - len];
	}
	
	for (i = 0; i < len; i++)
	{
		s[i] = tmp[i];
	}

	free(tmp);
	return 0;
}

int main141()
{
	char s[] = "ABCDE";

	round(s, 2);
	puts(s);
	return 0;
}