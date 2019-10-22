#include <iostream>
using namespace std;

class TestBase
{
protected:
	int m_a;
public:
	TestBase(int i) :
		m_a(i)
	{

	}

	void func(int i)
	{
		cout << "我是父类的函数" << endl;
	}
};

class Test : private TestBase
{
public:
	int m_b;

	Test(int a, int b) :
		TestBase(a),
		m_b(b)
	{

	}

	void func()
	{
		cout << "我是子类的函数" << endl;

		TestBase::func(2);
	}
};

int main2()
{
	//Test t(5, 6);

	TestBase * ptb = new TestBase(6);
	Test * pb = (Test *)ptb;

	//pb->m_b = 5;

	//t.m_b = 7;
	//t.m_a = 7;

	return 0;
}