#include <stdio.h>
#include <string.h>

void reversestr(char * str, int start, int end)
{
	char tmp;
	int i, j;
	for (i = start, j = end - 1; i < j; i++, j--)
	{
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
	}
}

char * reverseWordN(char * str)
{
	int i;
	int start = 0;

	for (i = 0; str[i]; i++)
	{
		if (str[i] == ' ')
		{
			reversestr(str, start, i);
			start = i + 1;
		}
	}
	reversestr(str, start, i);
	reversestr(str, 0, i);
	return str;
}

char * reverseWordY(char * str)
{
	char * ptmp;
	char tmp[100] = { 0 };
	while (ptmp = strrchr(str, ' '))
	{
		strcat(tmp, ptmp + 1);
		strcat(tmp, " ");
		*ptmp = '\0';
	}
	strcat(tmp, str);
	strcpy(str, tmp);
	return str;
}

int main()
{
	char str[] = "I don't like study";

	puts(reverseWordY(str));
	return 0;
}