#include <stdio.h>
#include <ctype.h>
#define isBigLetter(ch) (ch <= 'Z' && ch >= 'A')

int isSmallLetter(char ch)
{
	return ch <= 'z' && ch >= 'a';
}

int main()
{
	char ch;
	
	while (1)
	{ 
		ch = getchar();
		if (ch == '@')
		{
			break;
		}

		if (isSmallLetter(ch))
		{
			putchar(ch - 32);
		}
		else if (isBigLetter(ch))
		{
			putchar(ch + 32);
		}
		else if (isalnum(ch))
		{
			//do nothing
		}
		else
		{
			putchar(ch);
		}
	}
	return 0;
}