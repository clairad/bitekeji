#include <stdio.h>

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

int main124()
{
	char src[] = "I'm a fashion student";
	int i;
	int start = 0, end;

	for (i = 0; src[i]; i++)
	{
		if (src[i] == ' ')
		{
			end = i - 1;
			reverse_part(src, start, end);
			start = i + 1;
		}
	}
	reverse_part(src, start, i - 1);
	reverse_part(src, 0, i - 1);
	puts(src);
	return 0;
}