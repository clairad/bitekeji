#include <iostream>
using namespace std;

class TestBase
{
public:
	int m_a;

	TestBase(int i):
		m_a(i)
	{

	}

	void func(int i)
	{
		cout << "我是父类的函数" << endl;
	}
};

class Test : public TestBase
{
public:
	int m_a;

	Test(int a, int b) :
		TestBase(a),
		m_a(b)
	{

	}

	void func()
	{
		cout << TestBase::m_a << endl;
		cout << "我是子类的函数" << endl;
	}
};

int main1()
{
#if 0
	Test t(5, 6);

	t.func();
#else
	Test * pt = new Test(5, 6);
	TestBase * ptb = pt;

	//cout << pt->m_a << endl;
	//cout << ptb->m_a << endl;

	pt->func();
	ptb->func(1);
#endif
	return 0;
}