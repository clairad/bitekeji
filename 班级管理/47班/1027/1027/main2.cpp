#include <iostream>
using namespace std;

class TestBase
{
public:
	virtual ~TestBase()
	{
		cout << "TestBase" << endl;
	}
};

class Test : public TestBase
{
public:
	virtual ~Test()
	{
		cout << "Test" << endl;
	}
};


int main2()
{
	Test * pt = new Test;
	TestBase * ptb = pt;

	delete ptb;

	return 0;
}