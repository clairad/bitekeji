#include <stdio.h>
#include <ctype.h>
/*
の　の
　も
　へ
*/
int d5p4()
{
	char ch;
	while (1)
	{
		ch = getchar();
		if (isalpha(ch))
		{
			putchar(ch ^ 32);
			//^ 可以改变某一位的状态
			//| 可以强制某一位变1
			//&~ 可以强制某一位变0
		}
		else if (isdigit(ch))
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