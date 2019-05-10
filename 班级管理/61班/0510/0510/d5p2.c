#include <stdio.h>

int main52()
{
	int a[10] = { 2, 3, 5, 7, 8, 9, 10, 12, 14, 17 };
	int i;
	int find = 11;
	int left = 0;
	int right = 9;
#if 0
	for (i = 0; i < 10; i++) //±éÀú
	{
		if (find == a[i])
		{
			break;
		}
	}

	printf("%d\n", i);
#endif
	int mid;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (a[mid] > find)
		{
			right = mid - 1;
		}
		else if (a[mid] < find)
		{
			left = mid + 1;
		}
		else
		{
			printf("%d\n", mid);
			return 0;
		}
	}

	printf("Ã»ÕÒµ½\n");
	return 0;
}