#include <iostream>
#include <vector>
using namespace std;

class Base
{
public:
	int m_b = 5;

	virtual void func()
	{

	}
};

class Test : public Base
{};

int main2()
{/*
	try
	{
		Base b;
		Test * t = dynamic_cast<Test *>(&b);
		if (!t)
		{
			throw bad_cast("父类指针不能转换为子类指针");
		}

	}
	catch (bad_cast &x)
	{
		cout << x.what();
	}
	*/

	try
	{
		vector<int> v;

		v.at(10) = 0;

	}
	catch (out_of_range &x)
	{
		cout << x.what();
	}
	return 0;
}