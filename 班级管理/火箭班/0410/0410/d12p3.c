#include <stdio.h>

int main123()
{
	int arr[9] = { 1, 3, 5, 2, 1, 2, 4, 3, 4 };
	int res = 0;
	int i;

	for (i = 0; i < 9; i++)
	{
		res ^= arr[i];
	}
	printf("%d\n", res);
	return 0;
}