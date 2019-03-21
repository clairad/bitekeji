#include <stdio.h>
#define WIDTH 2 //控制图片宽度，也就是星星之间空格的个数，默认为1

int main()
{
	int i, j, k, l, m;
	int n, sub, floor, gap = 0;

	printf("请输入总行数和每个星星金字塔的行数：\n");
	scanf("%d%d", &n, &sub);

	if (n % sub) //计算层数，如果是非整数层，要拿到一个gap值。
	{
		floor = n / sub + 1;
		gap = floor * sub - n;
	}
	else
	{
		floor = n / sub;
	}

	for (i = 1; i <= floor; i++) //总层数
	{
		for (j = 1; j <= (i == floor ? sub - gap : sub); j++) //每一层的第n行。如果是最后一层，要判断有gap的情况
		{ 
			for (k = 0; k < n - ((i - 1) * sub + j); k++) //(i - 1) * sub + j是行数，打印前面的空格
			{
				putchar(' ');
				for (m = 0; m < WIDTH; m++) //宽度控制在这里体现，下同
				{
					putchar(' ');
				}
			}

			for (k = 0; k < i; k++) //打印层数次星星金字塔
			{
				for (l = 0; l < j * 2 - 1; l++) //2n-1个星星，n是这一层中的行数
				{ 
					putchar('*');
					for (m = 0; m < WIDTH; m++)
					{
						putchar(' ');
					}
				}

				if (k == i - 1) break; //最后一次不需要在后面补空格
				
				for (l = 0; l < sub * 2 - j * 2 + 1; l++) //补对应空格，方便下一次打印。要打印：金字塔层数*2-(2n-1)个空格
				{
					putchar(' ');
					for (m = 0; m < WIDTH; m++)
					{
						putchar(' ');
					}
				}
			}
			putchar('\n'); //一行结束
		}
	}
	system("pause");
	return 0;
}