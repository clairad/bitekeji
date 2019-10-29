#include <iostream>
using namespace std;

class Base
{
public:
	int m_i;

	virtual void func1()
	{
		cout << "Base::func1" << endl;
	}
};

class TestBase : virtual public Base
{
public:
	int m_a = 3;

	virtual void func1()
	{
		cout << "TestBase::func1" << endl;
	}
};

class TestBase2 : virtual public Base
{
public:
	int m_b = 2;

	virtual void func1()
	{
		cout << "TestBase2::func1" << endl;
	}
};

class Test : public TestBase, public TestBase2
{
public:
	virtual void func1()
	{
		cout << "Test::func1" << endl;
	}
};


int main()
{
	Test t;
	//Base * pb = &t;
	//Base2 * pb2 = &t;


	//pb->func1();
	//pb2->func2();

	//cout << pb->m_a << endl;
	//cout << pb2->m_b << endl;

	//t.TestBase::m_i;
	//t.TestBase2::m_i;

	return 0;
}