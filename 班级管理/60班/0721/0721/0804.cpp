#include <stdio.h>

void printLog(int data[][201], int n)
{
	int i, j;
	
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			printf("%2d ", data[i][j]);
		}
		putchar('\n');
	}
}

int main()
{
	int data[201][201] = { 0 };
	int mind[201][201] = { 0 };
	int maxd[201][201] = { 0 };
	
	int n;
	int i, j, k, min = 0x7fffffff, tmp;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		scanf("%d", &data[i][i]);
	}
	
	for(i = 0; i < n - 1; i++)
	{
		data[i + n][i + n] = data[i][i];
	}
	
	n = 2 * n - 1;
	for (i = 1; i < n / 2 + 1; i++)
	{
		for (j = 0; j < n - i; j++)
		{
			data[j][i + j] = data[j + 1][i + j] + data[j][j]; 
			for (k = 0; k < i; k++)
			{
				tmp = mind[j][j + k] + mind[j + k + 1][i + j];
				if(min > tmp)
				{
					min = tmp;
				}
			}
			mind[j][i + j] = min + data[j][i + j];
			min = 0x7fffffff; 
		}
	}
	
	
	min = 0x7fffffff;
	for (i = 0; i < n / 2 + 1; i++)
	{
		if (min > mind[i][i + n / 2])
		{
			min = mind[i][i + n / 2];
		}
	}
	
	printf("%d\n", min);
	
	int max = 0x80000000;
	for (i = 1; i < n / 2 + 1; i++)
	{
		for (j = 0; j < n - i; j++)
		{
			//data[j][i + j] = data[j + 1][i + j] + data[j][j]; 
			for (k = 0; k < i; k++)
			{
				tmp = maxd[j][j + k] + maxd[j + k + 1][i + j];
				if(max < tmp)
				{
					max = tmp;
				}
			}
			maxd[j][i + j] = max + data[j][i + j];
			max = 0x80000000;
		}
	}
	
	max = 0x80000000;
	for (i = 0; i < n / 2 + 1; i++)
	{
		if (max < maxd[i][i + n / 2])
		{
			max = maxd[i][i + n / 2];
		}
	}
	printf("%d\n", max);
	return 0;
}
