#include <stdio.h>

int c1()
{
	/*unsigned int a = 0x90000000;
	unsigned int b = 0x90000000;
	unsigned int c = 0;
	c = a + b;
	printf("%llx %x", a + b, c, 10);*/

	//char c = -1;
	//printf("%x", c);

	int a;
	float b;
	double c;
	//9876543210
	scanf("%2d%3f%4lf", &a, &b, &c);

	printf("a = %d, b = %d, c = %f\n", a, b, c);

	return 0;
}
/*
int checkData(int *p)
{
	int tmp[7] = { 0 };

	int i;
	for (i = 0; i < 5; i++)
	{
		if (tmp[p[i]])
		{
			return 0;
		}
		tmp[p[i]] = 1;
	}
	return 1;
}*/

int checkData(int *p)
{
	char tmp = 0;

	int i;
	for (i = 0; i < 5; i++)
	{
		tmp |= 1 << p[i];
	}
	return tmp == 0x3E;
}



int p1()
{
	int p[5];

	for (p[0] = 1; p[0] <= 5; p[0]++)
	{
		for (p[1] = 1; p[1] <= 5; p[1]++)
		{
			for (p[2] = 1; p[2] <= 5; p[2]++)
			{
				for (p[3] = 1; p[3] <= 5; p[3]++)
				{
					for (p[4] = 1; p[4] <= 5; p[4]++)
					{
						if ((p[1] == 2) + (p[0] == 3) == 1 &&
							(p[1] == 2) + (p[4] == 4) == 1 &&
							(p[2] == 1) + (p[3] == 2) == 1 &&
							(p[2] == 5) + (p[3] == 3) == 1 &&
							(p[4] == 4) + (p[0] == 1) == 1 &&
							checkData(p)
							)
						{
							for (int i = 0; i < 5; i++)
							{
								printf("%d ", p[i]);
							}
							putchar('\n');
						}
					}
				}
			}
		}
	}

	return 0;
}

int p2()
{
	int murder[4] = { 0 };
	/*A说：不是我。
	B说：是C。
	C说：是D。
	D说：C在胡说*/
	int i;
	for (i = 0; i < 4; i++)
	{
		murder[i] = 1;
		if ((murder[0] != 1) +
			(murder[2] == 1) +
			(murder[3] == 1) +
			(murder[3] != 1) == 3)
		{
			break;
		}
		murder[i] = 0;
	}

	putchar('A' + i);
	return 0;
}

void printArray(int * arr, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	putchar('\n');
}

void p3(int n)
{
	int data[30] = { 1 };

	int i, j;
	printf("1\n");
	for (i = 1; i < n; i++)
	{
		for (j = i; j > 0; j--)
		{
			data[j] += data[j - 1];
		}
		printArray(data, i + 1);
	}
}

void p3_1(int n)
{
	int data[30][30] = { 1 };

	int i, j;

	for (i = 1; i < n; i++)
	{
		data[i][0] = 1;
		for (j = 1; j <= i; j++)
		{
			data[i][j] = data[i - 1][j] + data[i - 1][j - 1];
		}
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j <= i; j++)
		{
			printf("%d ", data[i][j]);
		}
		putchar('\n');
	}
}

int main1()
{
	//p3_1(10);
	p3(10);

	return 0;
}