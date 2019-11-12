#include <iostream>
using namespace std;
/*
class Base
{
public:
	int m_b = 5;
};

class Test : public Base
{};*/

void func2()
{
	try
	{
		//Test a;

		//throw a;
	}
	catch (short & e)
	{

	}
}


void func()
{
	try
	{
		func2();
	}
	catch (char & e)
	{

	}
}

int main1()
{
	try
	{
		func();
	}
	catch (int & e)
	{
		cout << e;
	}
	/*catch (Test & e)
	{
		cout << e.m_b;
	}
	catch (Base & e)
	{
		cout << e.m_b;
	}*/
	catch (...)
	{
		cout << "À¬»øÍ°" << endl;
	}

	return 0;
}