#include <stdio.h>
#include <string.h>

void reverse_string1(char * start, char * end)
{
	char tmp = *start;
	*start = *end;
	*end = tmp;
	if (start + 1 < end - 1)
	{ 
		reverse_string1(start + 1, end - 1);
	}
}

void reverse_string(char * str)
{
	int end = strlen(str) - 1;
	char tmp = str[0];
	if (*str)
	{ 
		str[0] = str[end];
		str[end] = '\0';
		reverse_string(str + 1);
		str[end] = tmp;
	}
}

int main74()
{
	char str[10] = "bitekeji";
	reverse_string(str);

	puts(str);
	system("pause");
	return 0;
}