#include <stdio.h>
#include <string.h>

void reverse_part(char *str, int start, int end)
{
	int i, j;
	char tmp;

	for (i = start, j = end; i < j; i++, j--)
	{
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
	}
}

void round(char * src, int time)
{
	int len = strlen(src);
	int pos = len - time % len;
	reverse_part(src, 0, pos - 1);
	reverse_part(src, pos, len - 1);
	reverse_part(src, 0, len - 1);
}

void round_cat(char * src, int time)
{
	int len = strlen(src);
	int pos = len - time % len;
	char tmp[256] = { 0 };
	
	strcpy(tmp, src + pos);
	strncat(tmp, src, pos);
	strcpy(src, tmp);
}

int main141()
{
	char str[] = "ABCDEFGHIJKLMN";
	round_cat(str, 10);
	puts(str);
	return 0;
}