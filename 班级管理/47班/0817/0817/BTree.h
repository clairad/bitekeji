#ifndef _BTREE_H_
#define _BTREE_H_


typedef char BTDataType;

typedef struct BinaryTreeNode {
	BTDataType data;
	struct BinaryTreeNode* lchild;
	struct BinaryTreeNode* rchild;
}BTNode;

BTNode *BinaryTreeCreate(BTDataType * src);
void BinaryTreeDestory(BTNode* root);

void BinaryTreePrevOrder(BTNode* root);
void BinaryTreeInOrder(BTNode* root);
void BinaryTreePostOrder(BTNode* root);
void BinaryTreeLevelOrder(BTNode* root);

void BinaryTreePrevOrderNonR(BTNode* root);
void BinaryTreeInOrderNonR(BTNode* root);
void BinaryTreePostOrderNonR(BTNode* root);

int BinaryTreeComplete(BTNode* root);
#endif /*_BTREE_H_*/