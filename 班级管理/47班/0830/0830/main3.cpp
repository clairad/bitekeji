#include <iostream>
using namespace std;

class TestSt
{
public:
	int a;
	static int m_s_i;

	TestSt()
	{
		m_s_i++;
	}

	static void testst()
	{
		m_s_i = 4;
	}
};

int TestSt::m_s_i = 0;

int main()
{
/*	TestSt t1;

	cout << t1.m_s_i << endl;

	TestSt t2;

	cout << t1.m_s_i << endl;
	cout << t2.m_s_i << endl;

	TestSt t3;

	cout << t1.m_s_i << endl;
	cout << t2.m_s_i << endl;
	cout << t3.m_s_i << endl;
	*/
	TestSt::testst();
	cout << TestSt::m_s_i << endl;
	return 0;
}

