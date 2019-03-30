#include <stdio.h>
#include <ctype.h>
#define isSmallLetter(ch) ((ch) <= 'z' && (ch) >= 'a')

int isBigLetter(char ch)
{
	return ch <= 'Z' && ch >= 'A';
}

int main54()
{
	char ch;
	while (1)
	{
		ch = getchar();
		if (isSmallLetter(ch))
		{
			//putchar(ch - ('a' - 'A'));
			putchar(ch & ~(1 << 5));
		}
		else if (isBigLetter(ch))
		{
			putchar(ch | 1 << 5);
		}
		else if (isalnum(ch))
		{
			//do nothing
		}
		else if (ch == '$')
		{
			break;
		}
		else
		{
			putchar(ch);
		}
	}

	system("pause");
	return 0;
}