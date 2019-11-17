#include <stdio.h>
#include <math.h>

//根据功能确定参数和返回值
//粘，然后改改
//    定义缺失的变量；查看代码需要简化的部分；确定返回值

//基础原则：一个函数只做一件事
//代码要尽可能的易读
int judgePrime(int n)
{
	int i;
	int sqrtres = sqrt(n);
	for (i = 2; i <= sqrtres; i++)
	{
		if (n % i == 0)
		{
			return 0;
		}
	}

	return 1;
}

int d7p5()
{
	int n;
	
	for (n = 2; n <= 10000; n++)
	{
		if (judgePrime(n))
		{
			printf("%d\n", n);
		}
	}
	return 0;
}
