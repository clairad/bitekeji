#include <iostream>
#include <typeinfo>
using namespace std;

namespace wf{

class Base
{
public:
	int m_a;

	virtual void Func1()
	{
		cout << "Base::Func1" << endl;
	}

	virtual void Func2()
	{
		cout << "Base::Func2" << endl;
	}
};

class TestBase : public Base
{
public:
	virtual void Func1()
	{
		cout << "TestBase::Func1" << endl;
	}

	virtual void Func3()
	{
		cout << "TestBase::Func4" << endl;
	}

	virtual void Func4()
	{
		cout << "TestBase::Func4" << endl;
	}
};

class TestBase2 : public TestBase
{
	virtual void Func1()
	{
		cout << "TestBase2::Func1" << endl;
	}

	virtual void Func3()
	{
		cout << "TestBase2::Func3" << endl;
	}
};

};
typedef void(*PFUNC)();

int main4()
{
	wf::Base b;
	wf::TestBase2 tb;

	PFUNC * tmp = (PFUNC *)*(int *)&tb;

	int i;
	for (i = 0; tmp[i] != nullptr; i++)
	{
		printf("第%d个虚表地址：%p  ", i + 1, tmp[i]);
		tmp[i]();
	}

	return 0;
}


