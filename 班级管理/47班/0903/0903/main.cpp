#include <iostream>
#include <fstream>
using namespace std;

class FTest{
	int m_a;
	int m_b;
public:
	FTest() :
		m_a(0),
		m_b(0)
	{

	}

	FTest(int a, int b) :
		m_a(a),
		m_b(b)
	{

	}

	void setNum(int a, int b);

	friend ostream & operator << (ostream & os, FTest & data);
	friend istream & operator >> (istream & is, FTest & data);
	friend class FTest2;
};

class FTest2{
	const int i = 3;
public:
	FTest2()
	{
		FTest ft(2, 3);
		cout << ft.m_a << endl;
	}

	void input()
	{

	}
	
	void output() const
	{
		
	}
};



void FTest::setNum(int a, int b)
{
	m_a = a;
	m_b = b;
}

ostream & operator << (ostream & os, FTest & data)
{
	os << data.m_a << ' ' << data.m_b;
	return os;
}

istream & operator >> (istream & is, FTest & data)
{
	is >> data.m_a >> data.m_b;
	return is;
}



class A{
public:
	enum{
		SUN,
		MON,
		TUE,
		WED,
		TUR,
		FRI,
		SAT
	};

	static int s_a;

	class B{
		int a;
		int b;
		
	public:
		B() :
			a(0),
			b(0)
		{
			s_a = FRI;
		}
	}a;
	int b;
public:
	A():
		a(),
		b(0)
	{
		//b = a.a;
	}
};

int A::s_a = 3;

int main()
{/*
	int s = 4;

	{
		int a = 5;
		cout << s << endl;
	}

	cout << a << endl;
	*/
	const FTest2 as;
	as.input();

	FTest ft;
	ifstream is("1.txt");
	A::B b;

	int i = A::SUN;

	is >> ft;

	cout << ft << endl;

	is.close();
	return 0;
}