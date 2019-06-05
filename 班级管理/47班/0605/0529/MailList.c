#include <stdio.h>
#include <string.h>
#include "MailList.h"

struct MailList g_allMsg[1000];
int g_count;

int menu()
{
	int tmp, ret;
	printf("1.	添加联系人信息\n"
		"2.	删除指定联系人信息\n"
		"3.	查找指定联系人信息\n"
		"4.	修改指定联系人信息\n"
		"5.	显示所有联系人信息\n"
		"6.	清空所有联系人\n"
		"请输入选项：");
	ret = scanf("%d", &tmp);
	return ret ? tmp : -1;
}

void MailList()
{
	int op;
	int ret;
	char str[256] = { 0 };
	int searchRes[1001] = { 0 };
	while (1)
	{
		op = menu();
		switch (op)
		{
		case ADD_MSG:
			inputData();
			break;
		case DELETE_MSG:
			printf("请输入你要删除的条目：\n");
			memset(str, 0, sizeof(str));
			scanf("%s", str);
			ret = catchOneData(str);
			if (ret > 0)
			{ 
				deleteOneData(ret);
				printf("删除成功\n");
			}
			else
			{
				printf("删除失败\n");
			}
			break;
		case SEARCH_MSG:
			printf("请输入你要检索的字符串：\n");
			memset(str, 0, sizeof(str));
			memset(searchRes, 0, sizeof(searchRes));
			scanf("%s", str);
			searchData(str, searchRes);
			outputSearchData(searchRes);
			printf("共找到%d条数据\n", searchRes[0]);
			break;
		case CHANGE_MSG:
			break;
		case DISPLAY_MSG:
			outputData();
			break;
		case EMPTY_MSG:
			memset(g_allMsg, 0, g_count * sizeof(struct MailList));
			g_count = 0;
			break;
		case -1:
			printf("输入有误，请重新输入\n");
			break;
		default:
			printf("输入有误，请重新输入\n");
		}
	}
}

int main()
{
	MailList();
	return 0;
}