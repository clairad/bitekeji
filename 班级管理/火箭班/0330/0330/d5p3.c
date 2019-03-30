#include <stdio.h>
#include <string.h>
/*
strcpy(str1 = str2);
strcat(str1 += str2);
strcmp(str1 > str2);
strcasecmp(str1 > str2);
strlen
*/

int login(char pwd[])
{
	char input[65] = { 0 };
	int i;

	for (i = 0; i < 3; i++)
	{
		scanf("%s", input);
		if (!strcmp(input, pwd))
		{
			return 1;
		}
	}
	return 0;
}

int main53()
{
	char pwd[] = "biterocket";
	char input[65] = { 0 };
	int i;

	if (login(pwd))
	{
		printf("µÇÂ¼³É¹¦\n");
	}
	else
	{
		printf("µÇÂ¼Ê§°Ü\n");
	}
	
	system("pause");
	return 0;
}