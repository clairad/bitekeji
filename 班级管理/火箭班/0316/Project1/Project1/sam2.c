#include <stdio.h>

int main()
{
	int a = 10000;
	int b = -2;
	//1000 0000 0000 0000 0000 0000 0000 0010
	//1111 1111 1111 1111 1111 1111 1111 1110
	//fffffffe
	//00 00 00 0a

	int i = 1;
	char * p = (char *)&i;

	if (*p == 1)
	{
		printf("Ð¡¶ËÐò\n");
	}
	else
	{
		printf("´ó¶ËÐò\n");
	}

	return 0;
}