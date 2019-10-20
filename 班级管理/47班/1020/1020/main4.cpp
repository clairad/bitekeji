#include <iostream>
using namespace std;

class Truetype
{
public:
	static bool get()
	{
		return true;
	}
};

class Falsetype
{
public:
	static bool get()
	{
		return false;
	}
};

template <class T>
class TypeTraits
{
public:
	typedef Falsetype Jtype;
};

template <>
class TypeTraits<int>
{
public:
	typedef Truetype Jtype;
};

template <>
class TypeTraits<float>
{
public:
	typedef Truetype Jtype;
};

int main4()
{
	cout << TypeTraits<int>::Jtype::get() << endl;
	cout << TypeTraits<double>::Jtype::get() << endl;

	return 0;
}