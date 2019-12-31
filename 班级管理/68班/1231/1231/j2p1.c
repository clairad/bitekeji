#include <stdio.h>
#define BUFFER_SIZE 10

int yangSquare(int arr[][BUFFER_SIZE], int x, int y, int f)
{
	int i = 0, j = y - 1;

	while (i < x && j >= 0)
	{
		if (f > arr[i][j])
		{
			i++;
		}
		else if (f < arr[i][j])
		{
			j--;
		}
		else
		{
			return 1;
		}
	}
	return 0;
}

int j2p1()
{
	int arr[BUFFER_SIZE][BUFFER_SIZE] = { { 1, 3, 5 },
						  { 3, 5, 7 },
						  { 5, 7, 9 } };

	printf("%d", yangSquare(arr, 3, 3, 7));
						

	return 0;
}