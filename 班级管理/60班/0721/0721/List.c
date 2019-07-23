#include "List.h"
#include <stdio.h>
#include <stdlib.h>

void ListInit(List* plist)
{
	plist->_head = (ListNode *)malloc(sizeof(ListNode));
	plist->_head->_prev = plist->_head;
	plist->_head->_next = plist->_head;
}

void ListDestory(List* plist)
{
	while (plist->_head != plist->_head->_next)
	{
		ListPopFront(plist);
	}
	free(plist->_head);
	plist->_head = NULL;
}

void ListPushBack(List* plist, LTDataType x)
{
	ListInsertFront(plist->_head, x);
}

void ListPopBack(List* plist)
{
	ListErase(plist->_head->_prev);
}
void ListPushFront(List* plist, LTDataType x)
{
	ListInsertAfter(plist->_head, x);
}

void ListPopFront(List* plist)
{
	ListErase(plist->_head->_next);
}

void ListInsertFront(ListNode* pos, LTDataType x)
{
	ListNode * cur = (ListNode *)malloc(sizeof(ListNode));
	cur->_data = (LTDataType *)malloc(sizeof(LTDataType));
	ListNode * tmp = pos->_prev;

	*cur->_data = x;

	pos->_prev = cur;
	cur->_next = pos;
	tmp->_next = cur;
	cur->_prev = tmp;
}

void ListInsertAfter(ListNode* pos, LTDataType x)
{
	ListNode * cur = (ListNode *)malloc(sizeof(ListNode));
	cur->_data = (LTDataType *)malloc(sizeof(LTDataType));
	ListNode * tmp = pos->_next;

	*cur->_data = x;

	pos->_next = cur;
	cur->_prev = pos;
	tmp->_prev = cur;
	cur->_next = tmp;
}

void ListErase(ListNode* pos)
{
	pos->_prev->_next = pos->_next;
	pos->_next->_prev = pos->_prev;
	free(pos->_data);
	free(pos);
}
/*
void ListRemove(List* plist, LTDataType x)
{
	ListNode * cur = ListFind(plist, x);

	if (cur)
	{
		ListErase(cur);
	}
}*/

void ListDistinct(List* plist)
{
	ListNode * cur;
	for (cur = plist->_head->_next; cur != plist->_head->_prev; )
	{
		if (Contactcmp(*cur->_data, *cur->_next->_data) == 0)
		{
			ListErase(cur->_next);
		}
		else
		{
			cur = cur->_next;
		}
	}
}

void ListRankInsert(List *plist, LTDataType x)
{
	ListNode * cur;

	for (cur = plist->_head->_next; cur != plist->_head; cur = cur->_next)
	{
		if (Contactcmp(*cur->_data, x) >= 0)
		{
			break;
		}
	}
	ListInsertFront(cur, x);
}

void ListMerge(List* plist1, List* plist2)
{
	ListNode *cur1 = plist1->_head->_next, *cur2 = plist2->_head->_next;
	//cur1和cur2是链表1和链表2的第一个数据
	ListNode *tmp1, *tmp2;
	while (cur1 != plist1->_head && cur2 != plist2->_head)//双链表遍历的跳出条件
	{
		if (Contactcmp(*cur1->_data, *cur2->_data) > 0) //如果链表1当前节点的数据比链表2的大，说明链表2的这个节点应该插到链表1的当前节点前面
		{
			tmp1 = cur1->_prev; //由于cur1的prev会被修改，这里做一个备份
			tmp2 = cur2->_next; //由于cur2的next会被修改，这里做一个备份

			cur1->_prev = cur2; //cur1左手拉起cur2
			cur2->_next = cur1; //cur2右手拉起cur1，两手相连
			tmp1->_next = cur2; //tmp1(cur1的prev)的右手拉起cur2
			cur2->_prev = tmp1; //cur2的左手拉起tmp1，两手相连

			cur2 = tmp2; //cur2找到它的下一个节点
		}
		else
		{
			cur1 = cur1->_next; //如果cur1的值反而较小，那么直接找他的下一个节点
		}
	}

	if (cur1 == plist1->_head) //如果遍历结束后，list1到末尾了，证明list2还没结束，而且list2剩下的节点的值都比list1大，所以要把list2剩下的所有节点挂在list1后面
	{
		tmp2 = plist2->_head->_prev; //记录需要挂的最后一个节点，cur2就是需要挂的第一个节点，也就是要把cur2到tmp这一段节点挂在cur1的末尾

		cur2->_prev = cur1->_prev; //让cur2的左手拉起list1的最后一个节点（此时cur1就是list1的头，所以cur1的左手拉的就是list1的尾节点）
		cur1->_prev->_next = cur2; //让list1的尾节点的右手拉起cur2，牵手成功，此时cur2被挂在了list1的尾部

		tmp2->_next = cur1; //中间的所有节点不需要操作，下一个要操作的只有尾节点tmp，让tmp的右手拉起list1的头。
		cur1->_prev = tmp2; //list1的头的左手拉起tmp2，牵手成功，tmp2成了list1的尾节点
	}
	//如果遍历结束后，是list2到了末尾，那么说明list2的元素已经全部插入list1中了，则直接释放头。

	free(plist2->_head); //最后，释放掉list2中仅剩的头部
}

void ListPrint(List* plist)
{
	ListNode * cur;

	printf("head->");
	for (cur = plist->_head->_next; cur != plist->_head; cur = cur->_next)
	{
		printData(*cur->_data);
	}
	printf("head");
}

void ListFind(List *plist, char *find, SeqList *psl)
{
	ListNode * cur;
	int flag;
	char * ret;
	char age[4];
	for (cur = plist->_head->_next; cur != plist->_head; cur = cur->_next)
	{
		do{
			flag = 1;
			ret = strstr(cur->_data->name, find);
			if (ret)
			{
				break;
			}

			ret = strstr(cur->_data->phonenum, find);
			if (ret)
			{
				break;
			}

			sprintf(age, "%d", cur->_data->age);
			if (!strcmp(age, find))
			{
				break;
			}

			ret = strstr(cur->_data->address, find);
			if (ret)
			{
				break;
			}

			flag = 0;
		} while (0);

		if (flag)
		{
			SeqListPushBack(psl, cur);
		}
	}
}
