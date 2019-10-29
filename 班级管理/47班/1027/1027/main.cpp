#include <iostream>
using namespace std;

class TestBase
{
public:
	virtual void func()
	{
		cout << "I'm TestBase!" << endl;
	}
};

class TestBase2 : public TestBase
{
public:
	void func()
	{
		cout << "I'm TestBase2!" << endl;
	}
};

class TestBase3 : public TestBase2
{
public:
	void func()
	{
		cout << "I'm TestBase3!" << endl;
	}
};

int main1()
{
	/*
	TestBase tb;

	Test t;
	TestBase * ptb = &t;

	ptb->func();
	tb.func();
	t.func();*/

#if 1
	TestBase3 t3;
	TestBase2 * pt2 = &t3;
	TestBase * pt = pt2;
	
	t3.func();
	pt2->func();
	pt->func();
#else
	TestBase2 t2;
	TestBase * pt = &t2;

	t2.func();
	pt->func();
#endif
	return 0;
}