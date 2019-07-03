#ifndef _SLIST_H_
#define _SLIST_H_
/*
链表如何遍历

for(cur = head; cur; cur = cur->next)
{
	cur;
}

for(cur = head->next; cur != head; cur = cur->next)
{
	cur; 
}

*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLTDataType;

typedef struct SListNode
{
	SLTDataType _data;
	struct SListNode* _next;
}SListNode;

typedef struct SList {
	SListNode* _head;
}SList;

void SListInit(SList* plist);
void SListDestory(SList* plist);

SListNode* BuySListNode(SLTDataType x);
void SListPushFront(SList* plist, SLTDataType x);
void SListPopFront(SList* plist);
SListNode* SListFind(SList* plist, SLTDataType x);
void SListInsertAfter(SListNode* pos, SLTDataType x);
void SListEraseAfter(SListNode* pos);
void SListRemove(SList* plist, SLTDataType x);
void SListReverse(SList* plist);

void SListPrint(SList* plist);
void TestSList();

SListNode * getIntersectionNode(SList* listA, SList* listB);
//void SListInsertFront(SList* plist, SLTDataType x);
int SListHasCycle(SList* plist);
SListNode * SListDetectCycle(SList* plist);

#endif //_SLIST_H_