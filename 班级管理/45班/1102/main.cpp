#include <stdio.h>

int arr[7];
//n和sum是做循环跳出条件的，k和level是控制循环层数的，last是沟通两层循环间的
void print_Way(int n, int k, int level, int last, int sum)
{
	int i;
	if (level >= k - 1)
	{   //最里层循环的处理
		for (i = 0; i < k - 1; i++)
		{
			printf("%d ", arr[i]);
		}
		printf("%d\n", n - sum);
		return;
	}

	for (i = last; i <= n - sum - i; i++) //每一层循环的循环头
	{
		arr[level] = i;
		print_Way(n, k, level + 1, i, sum + i);
	}
}


int main()
{
	int n = 8;
	int k = 4;

	print_Way(n, k, 0, 1, 0);

	/*int i, j, sum = 0;
	for (i = 1; i <= n - sum - i; i++)
	{
		arr[0] = i;
		sum += i;
		for (j = i; j <= n - sum - j; j++)
		{
			arr[1] = j;
			arr[2] = n - i - j;
			printf("%d %d %d\n", arr[0], arr[1], arr[2]);
		}
		sum -= i;
	}*/


	return 0;
}