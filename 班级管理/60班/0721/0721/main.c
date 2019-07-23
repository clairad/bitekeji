#include <stdio.h>
#include <string.h>
#include "contact.h"

typedef struct Con Con;

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
	char str[256] = { 0 };
	List list;
	ListInit(&list);

	while (1)
	{
		op = menu();

		switch (op)
		{
		case ADD_MSG:
			contactAdd(&list, createData());
			break;
		case DELETE_MSG:
			printf("请输入你要删除的条目的信息：\n");
			memset(str, 0, sizeof(str));
			scanf("%s", str);
			contactDelete(&list, str);
			break;
		case SEARCH_MSG:
			printf("请输入你要检索的字符串：\n");
			memset(str, 0, sizeof(str));
			scanf("%s", str);
			contactFind(&list, str);
			break;
		case CHANGE_MSG:
			break;
		case DISPLAY_MSG:
			ListPrint(&list);
			break;
		case EMPTY_MSG:
			ListDestory(&list);
			ListInit(&list);
			break;
		case -1:
			printf("输入有误，请重新输入\n");
			break;
		default:
			printf("输入有误，请重新输入\n");
		}
	}
	ListDestory(&list);
}

int main()
{
	MailList();
	return 0;
}