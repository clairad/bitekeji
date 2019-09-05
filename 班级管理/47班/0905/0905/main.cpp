#include <iostream>
#include <stdlib.h>
using namespace std;

#define __IN

class test
{
	int m_a;
	int m_b;
	int *m_pt;
public:
	test() :
		m_a(0),
		m_b(0)
	{
		m_pt = new int;
	}

	test(__IN int a, __IN int b) :
		m_a(a),
		m_b(b)
	{
		m_pt = new int;
	}

	~test()
	{
		delete m_pt;
	}

	void printTest()
	{
		cout << m_a << ' ' << m_b << endl;
	}
};

int main()
{
	test a;
	test *pa = new test(3, 6);

	pa->printTest();

	delete pa;
	return 0;
}