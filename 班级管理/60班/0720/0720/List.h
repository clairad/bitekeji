#ifndef _LIST_H_
#define _LIST_H_

#include "seqlist.h"
#include "contact.h"

typedef struct Contact LTDataType;

typedef struct ListNode {
	struct ListNode* _next;
	struct ListNode* _prev;
	LTDataType * _data;
}ListNode;

typedef struct List {
	ListNode* _head;
}List;

void ListInit(List* plist);
void ListDestory(List* plist);

void ListPushBack(List* plist, LTDataType x);
void ListPopBack(List* plist);
void ListPushFront(List* plist, LTDataType x);
void ListPopFront(List* plist);

void ListInsertFront(ListNode* pos, LTDataType x);
void ListInsertAfter(ListNode* pos, LTDataType x);
// 删除pos位置的节点
void ListErase(ListNode* pos);
void ListRemove(List* plist, LTDataType x);

void ListDistinct(List* plist);
void ListMerge(List* plist1, List* plist2);

void ListPrint(List* plist);
void ListRankInsert(List *plist, LTDataType x);

void ListFind(List *plist, char *find, SeqList *psl);

#endif /*_LIST_H_*/
