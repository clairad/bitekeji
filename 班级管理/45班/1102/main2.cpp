#include <stdio.h>

int count;
void printWay(int n, int k, int level, int last, int sum)
{
	int i;
	if (level >= k - 1)
	{   
		count++;
		return;
	}

	for (i = last; i <= n - sum - i; i++) //每一层循环的循环头
	{
		printWay(n, k, level + 1, i, sum + i);
	}
}


int main2()
{
	int n = 12;
	int k = 6;

	printWay(n, k, 0, 1, 0);

	printf("%d", count);
	return 0;
}