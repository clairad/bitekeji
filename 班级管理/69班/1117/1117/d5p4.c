#include <stdio.h>
#include <ctype.h>
#define IS_SMALL_LETTER(a) (a <= 'z' && a >= 'a')

int d5p4()
{
	char ch = '\0';
	while (ch != '\n')
	{
		ch = getchar();
		if (ch <= 'Z' && ch >= 'A')
		{
			ch += 'a' - 'A';
		}
		else if (IS_SMALL_LETTER(ch))
		{
			ch -= 'a' - 'A';
		}
		else if (isdigit(ch))
		{
			continue;
		}

		putchar(ch);
	}


	return 0;
}