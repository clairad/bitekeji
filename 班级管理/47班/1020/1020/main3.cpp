#include <iostream>
using namespace std;

template<class T1, class T2>
class Test{
	T1 m_a;
	T2 m_b;
public:
	Test()
	{
		cout << "T1, T2" << endl;
	}
};

template<>
class Test<int, char>{
	int m_a;
	char m_b;
public:
	Test()
	{
		cout << "int char" << endl;
	}
};

template<class T1>
class Test<T1, double>{
	T1 m_a;
	double m_b;
public:
	Test()
	{
		cout << "t1 double" << endl;
	}
};

template<class T1, class T2>
class Test<T1 *, T2 *>{
	T1 * m_a;
	T2 * m_b;
public:
	Test()
	{
		cout << "T1 *, T2 *" << endl;
	}
};

template<class T1, class T2>
class Test<T1 &, T2 &>{
	T1 & m_a;
	T2 & m_b;
public:
	Test(T1 &a, T2 &b) :
		m_a(a),
		m_b(b)
	{
		cout << "T1 &, T2 &" << endl;
		m_a = 8;
	}
};

int main3()
{
	Test<float, double> t1;
	Test<int, char> t2;
	Test<int *, float *> t3;
	int a = 0;
	char b = 0;
	Test<int &, char&> t4(a, b);

	cout << a << endl;
	return 0;
}