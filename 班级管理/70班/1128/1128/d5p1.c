#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

void getNum(int src[])
{
	int pool[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	srand((unsigned)time(NULL));

	int tmp;
	int i;
	for (i = 0; i < 4; i++)
	{
		tmp = rand() % 10;
		while (1)
		{ 
			if (pool[tmp] != -1)
			{ 
				src[i] = pool[tmp];
				pool[tmp] = -1;
				break;
			}
			
			tmp++;
			if (tmp == 10)
			{
				tmp = 0;
			}
		}
	}
}

int printArray(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	putchar('\n');
}

int printAB(int guess[], int src[])
{
	int i, j;
	int countA = 0, countB = 0;

	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (guess[i] == src[j])
			{
				countB++;
				break;
			}
		}
	}

	for (i = 0; i < 4; i++)
	{
		if (guess[i] == src[i])
		{
			countA++;
		}
	}

	printf("%dA%dB\n", countA, countB - countA);

	if (countA == 4)
	{
		return 1;
	}
	return 0;
}

int d5p1p()
{
	int src[4];
	int guess[4];

	getNum(src);
	//printArray(src, 4);
	int i, j;
	for (i = 1; i <= 8; i++)
	{ 
		printf("第%d次：", i);
		for (j = 0; j < 4; j++)
		{
			scanf("%d", &guess[j]);
		}

		if (printAB(guess, src))
		{
			printf("您赢了！\n");
			return 0;
		}
	}

	printf("您输了！\n答案是：");
	printArray(src, 4);
	return 0;
}

int d5p1()
{
	srand((unsigned)time(NULL));

	int i = rand() % 1000 + 1;

	//int i = rand() % 11 - 5;
	//2.13~3.25
	//double i = (rand() % 113 + 213) / 100.0;
	int n;
	while (1)
	{
		scanf("%d", &n);

		if (n == i)
		{
			printf("猜中了\n");
			break;
		}

		if (n < i)
		{
			printf("猜小了\n");
		}
		else
		{
			printf("猜大了\n");
		}
	}

	return 0;
}