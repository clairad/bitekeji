#include <iostream>
#include <algorithm>
#include "binaryTree.h"
using namespace std;

int main()
{
	//int arr[] = { 1, 2, -1, -1, 3, -1, -1 };
	//wf::Tree<int> tr2(arr, -1);

	//wf::Tree<char> tr("ABD##E##CFH##I##G##", '#');

	int arr[] = { 5, 8, 4, 12, -1, -1, 18, 17, -1, -1, 21, -1, -1, 9, -1, 7, -1, -1, 7, 6, -1, 5, 11, -1, -1, -1, 3, 4, -1, -1, 1, 14, -1, -1, -1 };
	wf::Tree<int> tr(arr, -1);
	/*
	tr.pre_order();
	cout << endl;
	tr.in_order();
	cout << endl;
	tr.post_order();
	cout << endl;
	//tr.test();

	tr.level_order();
	cout << endl;
	tr.everyline_level_order();
	*/

	tr.max_level_order();
	return 0;
}