#include <stdio.h>

int main()
{
	int i, n, sn;
	char end[30] = { 0 };
	int count = 28;
	scanf("%d%d", &n, &sn);

	for (i = n; i; i /= sn)
	{
		end[count--] = "0123456789ABCDEFGHIJK"[i % sn];
	}

	printf("%d=%s(base%d)\n", n, end + count + 1, sn);
	system("pause");
	return 0;
}
/*



1333122
-1 1 1 1 -1 0 0
   11010101110000
11011010101110000


-1 -2 0 0 0 -2 -1 0
   1111111010000
1110000000101100
11011010101110000

11302022
-1 -1 1 -2 0 -2 0 0
1111011000100000
1111011000100000


00 0
01 1
10 -2
11 -1*/