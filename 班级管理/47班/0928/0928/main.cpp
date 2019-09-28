#include <iostream>
#include "mlist.h"
#include <list>
using namespace std;

int main()
{
	wf::list<int> l(4, 5);
	int arr[5] = { 1, 3, 5, 7, 9 };
	wf::list<int> l2(arr, arr + 5);
	wf::list<int> l3 = l2;

	for (auto i = l3.begin(); i != l3.end(); i++)
	{
		cout << *i << ' ';
	}

	return 0;
}

int ltest3()
{
	int arr[5] = { 1, 3, 5, 7, 9 };
	list<int> l4(arr, arr + 5);
	list<int> l5(l4.begin(), l4.end());

	int arr2[5] = { 2, 4, 6, 8, 10 };
	list<int> l6(arr2, arr2 + 5);

	l5.merge(l6);

	for (auto &i : l5)
	{
		cout << i << ' ';
	}

	cout << l6.size();
	return 0;
}

int ltest2()
{
	list<int> l1;
	list<int> l2(4, 7);
	list<int> l3 = l2;

	int arr[5] = { 5, 2, 3, 1, 4 };
	list<int> l4(arr, arr + 5);
	list<int> l5(l4.begin(), l4.end());

	l5.sort();

	for (auto &i : l5)
	{
		cout << i << ' ';
	}
	return 0;
}

int ltest1()
{
	list<int> l1;
	list<int> l2(4, 7);
	list<int> l3 = l2;

	int arr[5] = { 1, 2, 3, 4, 5 };
	list<int> l4(arr, arr + 5);
	list<int> l5(l4.begin(), l4.end());

	int arr2[5] = { 6, 7, 8, 9, 10 };
	list<int> l6(arr2, arr2 + 5);

	//l5.back() = 6;


	list<int>::iterator pos = l5.end();
	pos--;

	//l5.insert(pos, 5);


	//l5.insert(pos, 4, 5);

	list<int>::iterator pos2 = l5.insert(pos, l6.begin(), l6.end());

	cout << *pos << endl;
	cout << *pos2 << endl;

	//pos = l5.erase(pos);

	/*list<int>::iterator pos2 = --pos;
	pos++;
	pos2--;

	cout << *pos << ' ' << *pos2 << endl;
	l5.erase(pos2, pos);

	cout << *pos2 << endl;*/

	//l5.swap(l2);

	for (auto &i : l5)
	{
		cout << i << ' ';
	}

	

	/*list<int>::reverse_iterator ril;

	for (ril = l5.rbegin(); ril != l5.rend(); ril++)
	{
		cout << *ril << ' ';
	}*/

	return 0;
}