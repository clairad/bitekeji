#if 0

#include <iostream>
#include <algorithm>
#define doubleZeroJudge(a) (a < 1E-6 && a > -1E-6)
using namespace std;

bool add(double a, double b, double &res)
{
	res = a + b;
	return true;
}

bool sub(double a, double b, double &res)
{
	res = a - b;
	return true;
}

bool mul(double a, double b, double &res)
{
	res = a * b;
	return true;
}

bool divi(double a, double b, double &res)
{
	if (doubleZeroJudge(b))
	{
		return false;
	}
	res = a / b;
	return true;
}

bool(*caculateWay[4])(double, double, double &) = { add, sub, mul, divi };

bool A1B2C3D(double * srcnum)
{
	double sum = 0;
	double tmp1, tmp2;
	int ret = 1;

	int i, j, k;
	for (i = 0; i < 4; i++)
	{
		ret = caculateWay[i](srcnum[0], srcnum[1], sum);
		if (!ret)
		{
			continue;
		}
		tmp1 = sum;
		for (j = 0; j < 4; j++)
		{
			ret = caculateWay[j](sum, srcnum[2], sum);
			if (!ret)
			{
				continue;
			}
			tmp2 = sum;
			for (k = 0; k < 4; k++)
			{
				ret = caculateWay[k](sum, srcnum[3], sum);
				if (doubleZeroJudge(sum - 24) && ret)
				{
					printf("((%.0f%c%.0f)%c%.0f)%c%.0f\n", 
						srcnum[0], "+-*/"[i],
						srcnum[1], "+-*/"[j],
						srcnum[2], "+-*/"[k],
						srcnum[3]);
					return true;
				}
				sum = tmp2;
			}
			sum = tmp1;
		}
	}
	return false;
}

bool A1B3C2D(double * srcnum)
{
	double sum = 0;
	double tmp1, tmp2;
	int ret = 1;

	int i, j, k;
	for (i = 0; i < 4; i++)
	{
		ret = caculateWay[i](srcnum[0], srcnum[1], tmp1);
		if (!ret)
		{
			continue;
		}
		for (j = 0; j < 4; j++)
		{
			ret = caculateWay[j](srcnum[2], srcnum[3], tmp2);
			if (!ret)
			{
				continue;
			}
			for (k = 0; k < 4; k++)
			{
				ret = caculateWay[k](tmp1, tmp2, sum);
				if (doubleZeroJudge(sum - 24) && ret)
				{
					printf("(%.0f%c%.0f)%c(%.0f%c%.0f)\n",
						srcnum[0], "+-*/"[i],
						srcnum[1], "+-*/"[k],
						srcnum[2], "+-*/"[j],
						srcnum[3]);
					return true;
				}
			}
		}
	}
	return false;
}

bool A2B1C3D(double * srcnum)
{
	double sum = 0;
	double tmp1, tmp2;
	int ret = 1;

	int i, j, k;
	for (i = 0; i < 4; i++)
	{
		ret = caculateWay[i](srcnum[1], srcnum[2], sum);
		if (!ret)
		{
			continue;
		}
		tmp1 = sum;
		for (j = 0; j < 4; j++)
		{
			ret = caculateWay[j](srcnum[0], sum, sum);
			if (!ret)
			{
				continue;
			}
			tmp2 = sum;
			for (k = 0; k < 4; k++)
			{
				ret = caculateWay[k](sum, srcnum[3], sum);
				if (doubleZeroJudge(sum - 24) && ret)
				{
					printf("(%.0f%c(%.0f%c%.0f))%c%.0f\n",
						srcnum[0], "+-*/"[j],
						srcnum[1], "+-*/"[i],
						srcnum[2], "+-*/"[k],
						srcnum[3]);
					return true;
				}
				sum = tmp2;
			}
			sum = tmp1;
		}
	}
	return false;
}

bool A3B1C2D(double * srcnum)
{
	double sum = 0;
	double tmp1, tmp2;
	int ret = 1;

	int i, j, k;
	for (i = 0; i < 4; i++)
	{
		ret = caculateWay[i](srcnum[1], srcnum[2], sum);
		if (!ret)
		{
			continue;
		}
		tmp1 = sum;
		for (j = 0; j < 4; j++)
		{
			ret = caculateWay[j](sum, srcnum[3], sum);
			if (!ret)
			{
				continue;
			}
			tmp2 = sum;
			for (k = 0; k < 4; k++)
			{
				ret = caculateWay[k](srcnum[0], sum, sum);
				if (doubleZeroJudge(sum - 24) && ret)
				{
					printf("%.0f%c((%.0f%c%.0f)%c%.0f)\n",
						srcnum[0], "+-*/"[k],
						srcnum[1], "+-*/"[i],
						srcnum[2], "+-*/"[j],
						srcnum[3]);
					return true;
				}
				sum = tmp2;
			}
			sum = tmp1;
		}
	}
	return false;
}

bool A3B2C1D(double * srcnum)
{
	double sum = 0;
	double tmp1, tmp2;
	int ret = 1;

	int i, j, k;
	for (i = 0; i < 4; i++)
	{
		ret = caculateWay[i](srcnum[2], srcnum[3], sum);
		if (!ret)
		{
			continue;
		}
		tmp1 = sum;
		for (j = 0; j < 4; j++)
		{
			ret = caculateWay[j](srcnum[1], sum, sum);
			if (!ret)
			{
				continue;
			}
			tmp2 = sum;
			for (k = 0; k < 4; k++)
			{
				ret = caculateWay[k](srcnum[0], sum, sum);
				if (doubleZeroJudge(sum - 24) && ret)
				{
					printf("%.0f%c(%.0f%c(%.0f%c%.0f))\n",
						srcnum[0], "+-*/"[k],
						srcnum[1], "+-*/"[j],
						srcnum[2], "+-*/"[i],
						srcnum[3]);
					return true;
				}
				sum = tmp2;
			}
			sum = tmp1;
		}
	}
	return false;
}

bool judgeRes(double * srcnum)
{
	return  A1B2C3D(srcnum) ||
			A1B3C2D(srcnum) ||
			A2B1C3D(srcnum) ||
			A3B1C2D(srcnum) ||
			A3B2C1D(srcnum);
}

bool entrance(double * srcnum, int n, int end)
{
	if (n >= end)
	{
		/*int i;
		for (i = 0; i < end; i++)
		{
			cout << srcnum[i] << ' ';
		}
		cout << endl;*/
		return judgeRes(srcnum);
	}

	int i;
	for (i = n; i < end; i++)
	{
		swap(srcnum[i], srcnum[n]);
		if (entrance(srcnum, n + 1, end))
		{
			return true;
		}
		swap(srcnum[n], srcnum[i]);
	}
	return false;
}


bool point24(double * srcnum)
{
	return entrance(srcnum, 0, 4);
}

int main()
{
	double srcnum[4];

	for (auto & e : srcnum)
	{
		cin >> e;
	}

	cout << point24(srcnum) << endl;

	return 0;
}
#else

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>  

const double PRECISION = 1E-6;
#define COUNT  4  
const int RESULT = 24;
#define  STRLEN  50
double number[COUNT] = { 0 };        //这里一定要用double,
char expression[COUNT][STRLEN] = { 0 };    //保存表达式  

#define TRUE 1
#define FALSE 0

int cnt = 0;

void Test(int n)
{
	int i = 0;
	int j = 0;
	int len = 0;
	//递归结束  
	if (1 == n){
		if (number[0] == RESULT)
		{
			// 避免输出前后括号  
			for (i = 1; i < strlen(expression[0]) - 1; i++)
			{
				printf("%c", expression[0][i]);
			}
			printf("\n");
			cnt++;
			return;
		}
		else
			return;
	}
	//递归过程  
	for (i = 0; i<n; i++){
		for (j = i + 1; j<n; j++){
			double a, b;
			char expa[STRLEN] = { 0 };
			char expb[STRLEN] = { 0 };
			a = number[i];
			b = number[j];
			// 删除number[j]元素，用number[n-1]填补  
			number[j] = number[n - 1];
			strcpy(expa, expression[i]);
			strcpy(expb, expression[j]);
			// 删除expression[j]元素，用expression[n-1]填补  
			strcpy(expression[j], expression[n - 1]);

			// 加法  
			len = strlen(expression[i]);
			sprintf(expression[i], "(%s+%s)", expa, expb);
			number[i] = a + b;
			Test(n - 1);
			//减号有两种情况,a-b与b-a  
			len = strlen(expression[i]);
			sprintf(expression[i], "(%s-%s)", expa, expb);
			number[i] = a - b;
			Test(n - 1);
			if (a != b)
			{
				len = strlen(expression[i]);
				sprintf(expression[i], "(%s-%s)", expb, expa);
				number[i] = b - a;
				Test(n - 1);
			}
			// 乘法  
			len = strlen(expression[i]);
			sprintf(expression[i], "(%s*%s)", expa, expb);
			number[i] = a*b;
			Test(n - 1);
			//除法也有两种情况,a/b与b/a  
			if (b != 0){
				len = strlen(expression[i]);
				sprintf(expression[i], "(%s/%s)", expa, expb);
				number[i] = a / b;
				Test(n - 1);
			}
			if ((a != 0) && (a != b)){
				len = strlen(expression[i]);
				sprintf(expression[i], "(%s/%s)", expb, expa);
				number[i] = b / a;
				Test(n - 1);
			}
			//恢复数组  
			number[i] = a;
			number[j] = b;
			strcpy(expression[i], expa);
			strcpy(expression[j], expb);
		}
	}
	return;
}
int main()
{
	int i = 0;

	for (i = 0; i<COUNT; i++)
	{
		scanf("%s", expression + i);
		number[i] = atoi(expression[i]);
	}

	Test(COUNT);

	if (0 != cnt)
	{
		printf("Total[%d], Success\n", cnt);
	}
	else
	{
		printf("Fail\n");
	}
	return 0;
}

#endif