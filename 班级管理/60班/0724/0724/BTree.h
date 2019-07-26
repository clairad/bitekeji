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
void BinaryTreePrevOrder(BTNode* root);
void BinaryTreeInOrder(BTNode* root);
void BinaryTreePostOrder(BTNode* root);

void BinaryTreeLevelOrder(BTNode* root);

void BinaryTreePrevOrderNonR(BTNode* root);
void BinaryTreeInOrderNonR(BTNode* root);
#endif /*_BTREE_H_*/