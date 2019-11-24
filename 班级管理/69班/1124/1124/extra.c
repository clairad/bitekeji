#include <stdio.h>
//               数据源参数   层数控制参数   沟通参数
void printsum(int * src, int n, int k, int start, int ans)
{
	if (k <= 0)
	{
		printf("%d\n", ans); //功能执行
		return;
	}

	int i;
	for (i = start; i < n; i++) //每层循环的循环头
	{ 
		printsum(src, n, k - 1, i + 1, ans + src[i]); //递归进入下次一层循环
	}
}

int main()
{
	int src[32] = { 0 };

	int n, k, i;

	scanf("%d%d", &n, &k);
	
	for (i = 0; i < n; i++)
	{
		scanf("%d", src + i);
	}

	printsum(src, n, k, 0, 0);
	/*
	int i, j, k;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			for (k = j + 1; k < n; k++)
			{ 
				printf("%d\n", src[i] + src[j] + src[k]);
			}
		}
	}
	*/
	return 0;
}

