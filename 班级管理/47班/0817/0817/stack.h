// 顺序表的动态存储
#ifndef _Stack_H_
#define _Stack_H_

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "BTree.h"

typedef BTNode * StDataType;

typedef struct Stack {
	StDataType* array;	// 指向动态开辟的数组
	size_t size;		// 有效数据个数
	size_t capicity;	// 容量空间的大小
}Stack;

// 基本增删查改接口
void StackInit(Stack* psl, size_t capacity);
void StackDestory(Stack* psl);

void StackPush(Stack* psl, StDataType x);
void StackPop(Stack* psl);
StDataType StackTop(Stack* psl);
int StackIsEmpty(Stack* psl);

#endif //_Stack_H_