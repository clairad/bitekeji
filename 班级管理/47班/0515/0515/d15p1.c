#include <stdio.h>

void findnum(int * src, int n, int * pnum1, int * pnum2)
{
	int i;
	int sum = 0;
	for (i = 0; i < n; i++)
	{
		sum ^= src[i];
	}

	int pos;

	for (pos = 0; !(sum & 1 << pos); pos++);

	int num1 = 0, num2 = 0;
	for (i = 0; i < n; i++)
	{
		if (src[i] & 1 << pos)
		{
			num1 ^= src[i];
		}
		else
		{
			num2 ^= src[i];
		}
	}
	*pnum1 = num1;
	*pnum2 = num2;
}

int main151()
{
	int arr[] = { 5, 3, 9, 1, 7, 5, 4, 7, 4, 2, 9, 2 };
	int num1, num2;
	findnum(arr, sizeof(arr) / sizeof(arr[0]), &num1, &num2);
	printf("%d %d\n", num1, num2);
	return 0;
}