#ifndef _LIST_H_
#define _LIST_H_

typedef int LTDataType;
typedef struct ListNode {
	LTDataType _data;
	struct ListNode* _next;
	struct ListNode* _prev;
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

ListNode* ListFind(List* plist, LTDataType x);

void ListInsertFront(ListNode* pos, LTDataType x);
void ListInsertAfter(ListNode* pos, LTDataType x);
// 删除pos位置的节点
void ListErase(ListNode* pos);
void ListRemove(List* plist, LTDataType x);

void ListPrint(List* plist);

#endif /*_LIST_H_*/