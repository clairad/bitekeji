#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int pwdJudge(char pwd[])
{
	char input[21] = { 0 };
	int i;

	for (i = 0; i < 3; i++)
	{
		scanf("%s", input);

		if (0 == strcmp(input, pwd))
		{
			return 1;
		}
	}
	return 0;
}

int main5()
{
	char pwd[21] = "bite49";

	if(pwdJudge(pwd))
	{ 
		printf("输入成功\n");
	}
	else
	{ 
		printf("输入失败\n");
	}
	return 0;
}