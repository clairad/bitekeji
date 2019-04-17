#include <stdio.h>
#define SIZE(a) (sizeof(a) / sizeof(a[0]))

int main123()
{
	int a[] = { 1, 5, 8, 2, 6, 4, 2, 8, 5, 1, 4 };
	int i;
	int res = 0;

	for (i = 0; i < SIZE(a); i++)
	{
		res ^= a[i];
	}
	printf("%d\n", res);
	return 0;
}