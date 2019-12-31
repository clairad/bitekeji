#include <stdio.h>
#include <string.h>

int cmp(const void * a, const void * b)
{
	return *(int *)a > *(int *)b;
}

void myqsort(void * base, size_t nitems, size_t size, int (*compar)(const void *, const void *))
{
	int i, j;
	char * st = (char *)base;
	char tmp[8];

	for (i = 0; i < nitems - 1; i++)
	{
		for (j = 0; j < nitems - 1 - i; j++)
		{
			if (compar(st + j * size, st + (j + 1) * size))
			{
				memcpy(tmp, st + j * size, size);
				memcpy(st + j * size, st + (j + 1) * size, size);
				memcpy(st + (j + 1) * size, tmp, size);
			}
		}
	}
}

int main()
{
	int arr[6] = {6,2,4,7,9,10};
	
	myqsort(arr, 6, sizeof(int), cmp);
	printf("%d %d %d %d %d %d", arr[0], arr[1], arr[2], arr[3], arr[4], arr[5]);
	return 0;
} 
