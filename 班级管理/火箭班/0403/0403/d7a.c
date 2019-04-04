#include <stdio.h>
#include <string.h>

void sum(int *arr, int k, int n, int count, int start)
{
	int i;
	if (k == 0)
	{
		printf("%d\n", count);
		return 0;
	}
	for (i = start; i < n; i++)
	{
		sum(arr, k - 1, n, count + arr[i], i + 1);
	}
}

int main()
{
	int n, k;
	int arr[20] = { 0 };
	int i;

	scanf("%d%d", &n, &k);
	for (i = 0; i < n; i++)
	{
		scanf("%d", arr + i);
	}

	sum(arr, k, n, 0, 0);

	return 0;
}

struct {
	int a;
	int b;
}s;