#include <stdio.h>

void reverse_word(char * start, char * end)
{
	int len = end - start;
	int i, j;

	char tmp;
	for (i = 0, j = len - 1; i < j; i++, j--)
	{
		tmp = start[i];
		start[i] = start[j];
		start[j] = tmp;
	}
}

void reverse(char * src)
{
	int i;
	char * start = src;
	char * end;

	for (i = 0; src[i]; i++)
	{
		if (src[i] == ' ')
		{
			end = src + i;
			reverse_word(start, end);
			start = end + 1;
		}
	}
	reverse_word(start, src + i);
	reverse_word(src, src + i);
}

int main()
{
	char test[50] = "I can sing jump rap basketball";

	reverse(test);

	puts(test);
	return 0;
}

int test()
{
	int a = 0x11223344;

	char * pc = (char *)&a;
	*pc = 0;

	printf("%x", a);

	return 0;
}