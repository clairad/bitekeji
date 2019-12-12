#include "RBTree.h"
#include <iostream>
using namespace std;

int main1()
{
	wf::RBTree<int> rbt;

	rbt.insert(6);
	rbt.insert(2);
	rbt.insert(7);
	rbt.insert(8);
	rbt.insert(4);
	rbt.insert(5);
	rbt.insert(3);
	rbt.insert(1);
	rbt.insert(10);
	rbt.insert(9);
	rbt.insert(6);
	rbt.insert(2);
	rbt.insert(7);
	rbt.insert(8);
	rbt.insert(4);
	rbt.insert(5);
	rbt.insert(3);
	rbt.insert(1);
	rbt.insert(10);
	rbt.insert(9);

	//rbt.test();

	for (auto & i : rbt)
	{
		cout << i << endl;
	}
	return 0;
}