#include <stdio.h>

int main152()
{
	int cover;
	int sum;

	int n;
	scanf("%d%d", &cover, &n);
	sum = cover;

	while (cover >= n)
	{
		sum += cover / n;
		cover = cover / n + cover % n;
	}

	printf("%d", sum + (cover == n - 1));

	return 0;
}