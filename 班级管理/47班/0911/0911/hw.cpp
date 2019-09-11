#include <iostream>
using namespace std;

class Test{
	int m_a;
public:
	Test(int a = 0) :
		m_a(a)
	{

	}

	Test operator ++ ()
	{
		m_a++;
		return *this;
	}

	Test operator ++ (int)
	{
		Test tmp = *this;
		m_a++;
		return tmp;
	}

	Test operator -- ()
	{
		m_a--;
		return *this;
	}

	Test operator -- (int)
	{
		Test tmp = *this;
		m_a--;
		return tmp;
	}

	friend ostream & operator << (ostream & os, Test & t);
};

ostream & operator << (ostream & os, Test & t)
{
	os << t.m_a;
	return os;
}

int testop()
{
	Test t(7);

	cout << t.operator++(0) << endl;
	cout << t << endl;

	return 0;
}

