#include <stdio.h>

int main()
{
	char tmp;

	while (1)
	{
		tmp = getchar();

		if (tmp == '`')
		{
			break;
		}

		if (tmp <= 'Z' && tmp >= 'A')
		{
			putchar(tmp + ('a' - 'A'));
		}
		else if (tmp <= 'z' && tmp >= 'a')
		{
			putchar(tmp - ('a' - 'A'));
		}
		else if (tmp <= '9' && tmp >= '0')
		{
			//do nothing
		}
		else
		{
			putchar(tmp);
		}
	}

	return 0;
}