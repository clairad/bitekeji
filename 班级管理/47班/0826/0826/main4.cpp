#include <iostream>
#include <typeinfo>
using namespace std;


int func1(int &a)
{
	return a;
}

inline int &func2(int &a)
{
	return a;
}

inline int *func3(int * pa)
{
	return pa;
}

int main1()
{
	int a = 3;
	cout << func1(a) << endl;
	cout << (func2(a) = 4) << endl;

	*func3(&a) = 5;

	return 0;
}
/*
auto add(auto &a, auto &b)
{
	return a + b;
}*/

int main()
{
	int i = 0;
	//auto arr[] = { 1, 2, 3 };
	//cout << typeid(j).name() << endl;
	//cout << typeid(k).name() << endl;
	return 0;
}