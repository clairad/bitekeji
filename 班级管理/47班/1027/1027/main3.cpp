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

class Test : public TestBase
{
public:
	virtual void func() override
	{
		cout << "I'm Test!" << endl;
	}
};

int main3()
{


	return 0;
}