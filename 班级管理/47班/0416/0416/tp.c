#include <stdio.h>
#define max(a, b) (a > b ? a : b)

int maxsum(int * data, int start, int end)
{
	if (start == end)
	{
		return data[start];
	}
	int left, right;

	left  = maxsum(data, start, end / 2);
	right = maxsum(data, end / 2 + 1, end);

	int tmpl = 0x80000000, tmpr = 0x80000000;
	int i;
	int tmp = 0;

	for (i = (start + end) / 2; i >= start; i--)
	{
		tmp += data[i];
		if (tmp > tmpl)
		{
			tmpl = tmp;
		}
	}
	tmp = 0;
	for (i = (start + end) / 2 + 1; i <= end; i++)
	{
		tmp += data[i];
		if (tmp > tmpr)
		{
			tmpr = tmp;
		}
	}

	int maxcross = tmpl + tmpr;
	return max(maxcross, max(left, right));
}

int main()
{
	int a[8] = { 1, -2, 7, -3, 6, -4, 9, -1 };
	printf("%d", maxsum(a, 0, 7));
	return 0;
}