#ifndef _Stack_H_
#define _Stack_H_

// 顺序表的动态存储

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int STDataType;

typedef struct Stack {
	STDataType* array;  // 指向动态开辟的数组
	size_t size;       // 有效数据个数
	size_t capacity;   // 容量空间的大小
}Stack;

// 基本增删查改接口
void StackInit(Stack* psl, size_t capacity);
void StackDestory(Stack* psl);

void CheckCapacity(Stack* psl);
void StackPush(Stack* psl, STDataType x);
void StackPop(Stack* psl);

STDataType StackFront(Stack* psl);
int StackIsEmpty(Stack* pq);

#endif /*_Stack_H_*/