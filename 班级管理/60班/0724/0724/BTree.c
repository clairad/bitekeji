#include "BTree.h"

BTNode* BinaryTreeCreate(BTDataType* a)
{
	BTNode * cur;
	static int i = 0;
	
	if (a[i] == ENDTAG)
	{
		i++;
		return NULL;
	}
	cur = (BTNode *)malloc(sizeof(BTNode));
	cur->_data = a[i];
	i++;
	cur->_left = BinaryTreeCreate(a);
	cur->_right = BinaryTreeCreate(a);

	return cur;
}