#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

int P01()
{
	int s, n;
	
	scanf("%d%d", &s, &n);
	
	int * wn = new int [n];
	int i;
	
	for (i = 0; i < n; i++)
	{
		scanf("%d", wn + i);
	}
	
	std::sort(wn, wn + n);
	
	for (i = 0; i < n && s - wn[i] > 0; i++)
	{
		s -= wn[i];
	}
	
	printf("%d", i);
	
	delete [] wn;
	return 0;
}

int P02()
{
	int s, n;
	
	scanf("%d%d", &s, &n);
	
	int * wn = new int [n];
	int i, j;
	
	for (i = 0; i < n; i++)
	{
		scanf("%d", wn + i);
	}
	
	std::sort(wn, wn + n);
	
	for (i = 0, j = n - 1; i < j; j--)
	{
		if(wn[i] + wn[j] < s)
		{
			i++;
		}
	}

	printf("%d", n - i);
	
	delete [] wn;
	return 0;
}

bool cmpFunc(int a, int b)
{
	return a > b;
}

int P03()
{
	int sum = 0, n;
	
	scanf("%d", &n);
	
	int * wn = new int [n];
	int i, j, tmp;
	
	for (i = 0; i < n; i++)
	{
		scanf("%d", wn + i);
	}
	
	std::sort(wn, wn + n, cmpFunc);
	
	for (i = n - 2; i >= 0; i--)
	{
		wn[i] += wn[i + 1];
		sum += wn[i];
		
		tmp = wn[i];
		
		for (j = i; j > 0 && wn[j - 1] < tmp; j--)
		{
			wn[j] = wn[j - 1];
		}
		
		wn[j] = tmp;
	}
	
	printf("%d", sum);
	
	return 0;
}

int main()
{
	int i;
	int j; 
	for (i = 0; i < n; i++)
	{
		if (num[i] == 0 || (num[i] + 1) * weight[i] > max)
		{
			packComplete(data, value[i], weight[i]);
		}
		else
		{
			for (j = 1; num[i] > j; j *= 2)
			{
				pack01(data, value[i] * j, weight[i] * j);
				num[i] -= j;
			}
			pack01(data, value[i] * num[i], weight[i] * num[i]);
		} 
	}
	
	return 0;
}

