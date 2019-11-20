#include "binarySortTree.h"
#include <iostream>
using namespace std;

int main()
{
	wf::BinarySortTree<int> bst;

	bst.insert(5);
	bst.insert(2);
	bst.insert(8);
	bst.insert(0);
	bst.insert(1);
	bst.insert(4);
	bst.insert(7);
	bst.insert(9);
	bst.insert(3);
	bst.insert(6);

	bst.erase(7);
	vector<int> v = bst.InOrder();

	for (auto & i : v)
	{
		cout << i << ' ';
	}
	return 0;
}