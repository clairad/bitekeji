#include <iostream>
using namespace std;

class TestBase
{
public:
	TestBase()
	{
		cout << "基类构造" << endl;
	}

	~TestBase()
	{
		cout << "基类析构" << endl;
	}
};

class Test : public TestBase
{
public:
	Test()
	{
		cout << "派生类构造" << endl;
	}

	void fun()
	{
		cout << "我是派生类" << endl;
	}

	~Test()
	{
		cout << "派生类析构" << endl;
	}
};



int main3()
{
	Test t;

	t.fun();

	return 0;
}