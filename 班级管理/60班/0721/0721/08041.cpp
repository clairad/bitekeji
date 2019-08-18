#include <stdio.h>

int data[100001];
int next[100001];
int maxu[100001];

int getdata()
{
	char tmp;
	int sum = 0;
	int count = 0;
	
	while( (tmp = getchar()) != '\n' )
	{
		if(tmp != ' ')
		{
			sum = sum * 10 + tmp - '0';
		}
		else
		{
			if(sum)
			{
				data[count] = sum;
				count++;
				sum = 0;
			}
		}
	}
	data[count] = sum;
	count++;
	
	return count;
}

int fillnext(int n, int * first)
{
	int i, j;
	int max = -1;
	int flag = 0;
	int nt = -1;
	int allmax = 0;
	int allnt = 0;
	
	for (i = n - 1; i >= 0; i--)
	{
		for (j = i + 1; j < n; j++)
		{
			if(data[i] >= data[j] && max <= maxu[j])
			{
				max = maxu[j];
				nt = j;
				flag = 1;
			}
		}
		if (!flag)
		{
			next[i] = -1;
		}
		else
		{
			next[i] = nt;
			maxu[i] = max + 1;
			flag = 0;
			if(allmax < maxu[i])
			{
				allmax = maxu[i];
				allnt = i;
			}
			max = -1;
		}
	}
	*first = allnt;
	return allmax + 1;
}

void printLog(int * src, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%d ", src[i]);
	}
	putchar('\n');
}

void deleteData(int i, int n)
{
	while(i != -1)
	{
		data[i] = -1;
		i = next[i];
	}
	
	int j = 0;
	for (i = 0; i < n; i++)
	{
		if(data[i] != -1)
		{
			next[j] = data[i];
			j++;
		}
	}
	
	for (i = 0; i < j; i++)
	{
		data[i] = next[i];
		next[i] = 0;
		maxu[i] = 0;
	}
}

int main()
{
	int size = getdata();
	
	int first;
	int max;
	int count = 0;
	
	while(size > 0)
	{
		max = fillnext(size, &first);
		if(count == 0)
		{
			printf("%d\n", max);
		}
		
		deleteData(first, size);
		
		size -= max;
		count++;
	}
	
	printf("%d\n", count);
	return 0;
} 
