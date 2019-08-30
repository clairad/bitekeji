#include <iostream>
using namespace std;

class Testop
{
public:
	int m_a;
	int m_b;

	Testop() :
		m_a(0),
		m_b(0)
	{

	}

	Testop(int a, int b) :
		m_a(a),
		m_b(b)
	{
	
	}

	void test1(int a, int b)
	{
		test2(2, 4);
	}

	void test2(int a, int b) const
	{
		//test1(2, 4);
	}

	Testop operator + (const Testop &s) const
	{
		Testop res;

		res.m_a = m_a + s.m_a;
		res.m_b = m_b + s.m_b;

		return res;
	}

	Testop & operator = (const Testop &s)
	{
		m_a = s.m_a;
		m_b = s.m_b;

		return *this;
	}
};


int main2()
{
	Testop a(3, 5);
	Testop b(2, 7);

	Testop c;
	const Testop d;
	c = c = a + b;



	cout << c.m_a << ' ' << c.m_b << endl;
	return 0;
}