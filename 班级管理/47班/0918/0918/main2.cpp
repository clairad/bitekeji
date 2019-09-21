#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> v;
	//vector<int> v2(v.begin() + 3, v.end() - 2);

	int i;

	cout << v.capacity() << endl;

	for (i = 1; i <= 70; i++)
	{
		v.push_back(i);
		cout << v.capacity() << endl;
	}
	cout << endl;
	for (i = 1; i <= 70; i++)
	{
		v.pop_back();
		cout << v.capacity() << endl;
	}
	/*
	vector<int>::iterator fi;
	vector<int>::reverse_iterator ri;

	for (fi = v.begin(); fi != v.end(); fi++)
	{
		cout << *fi << ' ';
	}
	cout << endl;

	for (ri = v.rbegin(); ri != v.rend(); ri++)
	{
		cout << *ri << ' ';
	}
	*/
	cout << v.capacity() << endl;
	return 0;
}