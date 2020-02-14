#include <iostream>
#include <vector>
#include <typeinfo>
using namespace std;

class A{};

template <class T>
struct unknown_class
{
	typedef T return_type;
};

/****************************************/

template <class unknown_class>
struct unknown_class_traits
{
	typedef typename unknown_class::value_type return_type;
};

template <class unknown_class>
typename unknown_class_traits<unknown_class>::return_type
func(unknown_class u)
{
	typedef typename unknown_class_traits<unknown_class>::return_type return_type;
	return return_type();
}

int main1()
{
	vector<int *> a;

	auto b = func(a);

	cout << typeid(b).name() << endl;
	return 0;
}