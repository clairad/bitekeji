#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void leftRoundEasy(char * src, int n)
{
	int i, j;
	char tmp;
	int len = strlen(src);
	n %= len;

	for (i = 0; i < n; i++)
	{
		tmp = src[0];
		for (j = 0; j < len - 1; j++)
		{
			src[j] = src[j + 1];
		}
		src[j] = tmp;
	}
}

void leftRoundNormal(char * src, int n)
{
	int len = strlen(src);
	char tmp[256] = { 0 };

	n %= len;
	strcpy(tmp, src + n); //CDEFG
	strncat(tmp, src, n);
	strcpy(src, tmp);
}

void part_reverse(char * begin, char * end)
{
	char tmp;

	for (; begin < end; begin++, end--)
	{
		tmp = *begin;
		*begin = *end;
		*end = tmp;
	}
}

void leftRound(char * src, int n)
{
	int len = strlen(src);
	n %= len;

	part_reverse(src, src + n - 1);
	part_reverse(src + n, src + len - 1);
	part_reverse(src, src + len - 1);
}

int j2p2()
{
	char src[] = "ABCDEFG";

	leftRound(src, 10);

	puts(src);
	return 0;
}