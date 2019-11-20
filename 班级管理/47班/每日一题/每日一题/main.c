#include <stdio.h>

int main1()
{
	int a;
	float b, c;
	scanf("%2d%3f%4f", &a, &b, &c);
	printf("\na=%d,b=%d,c=%f, extra = %x\n", a, b, c);

	return 0;
}

int main2()
{
	long long a = 4294967297ull;

	printf("%d %d\n", a);

	return 0;
}

/*
int main()
{
	double b = 765;
	double c = 4321;

	printf("%llx\n", *(long long *)&b);
	printf("%llx\n", *(long long *)&c);

	return 0;
}*/