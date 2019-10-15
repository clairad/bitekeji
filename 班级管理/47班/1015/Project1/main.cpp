#include <iostream>
#include <algorithm>
#include "binaryTree.h"
using namespace std;

int main()
{
	//int arr[] = { 1, 2, -1, -1, 3, -1, -1 };
	//wf::Tree<int> tr2(arr, -1);

	wf::Tree<char> tr("ABD##E##CFH##I##G##", '#');

	tr.pre_order();
	cout << endl;
	tr.in_order();
	cout << endl;
	tr.post_order();
	cout << endl;
	tr.test();
	return 0;
}