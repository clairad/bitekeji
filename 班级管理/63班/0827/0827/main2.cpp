#include <iostream>
#include <vector>
#include <typeinfo>
using namespace std;

void func(int a)
{
	cout << "1" << endl;
}

void func(int * pa)
{
	cout << "2" << endl; 
}

int main()
{	
	int * pa = nullptr;

	cout << typeid(nullptr).name() << endl;

	func(0);
	func(NULL);
	func((int *)NULL);

	return 0;
}

int main4()
{
	int arr[] = { 2, 5, 1, 3, 4 };
	vector<int> v;

	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	for (auto i : v)
	{
		cout << i << endl;
	}

	return 0;
}