#include <stdio.h>

int d2p4()
{
	int a, b, c;

	scanf("%d%d%d", &a, &b, &c);

	int tmp;

	if (a < b)
	{
		tmp = a;
		a = b;
		b = tmp;
	}

	if (b < c)
	{
		tmp = b;
		b = c;
		c = tmp;
	}

	if (a < b)
	{
		tmp = a;
		a = b;
		b = tmp;
	}

	printf("%d %d %d\n", a, b, c);

	/*
	//printf("%X", a);
	
	float f = 0.000001248;

	printf("%.2E", f);
	*/
	return 0;
}