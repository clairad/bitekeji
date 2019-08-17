#ifndef _BTREE_H_
#define _BTREE_H_

typedef char BTDataType;

typedef struct BinaryTreeNode {
	BTDataType data;
	struct BinaryTreeNode* lchild;
	struct BinaryTreeNode* rchild;
}BTNode;

BTNode *BinaryTreeCreate(BTDataType * src);



#endif /*_BTREE_H_*/