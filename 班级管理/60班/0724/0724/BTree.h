#ifndef _BTREE_H_
#define _BTREE_H_

#include <stdio.h>
typedef char BTDataType;
#define ENDTAG '#'

typedef struct BinaryTreeNode
{
	BTDataType _data;
	struct BinaryTreeNode* _left;
	struct BinaryTreeNode* _right;
}BTNode;

BTNode* BinaryTreeCreate(BTDataType* a);


#endif /*_BTREE_H_*/