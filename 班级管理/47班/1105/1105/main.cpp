#include <iostream>
#include <cstdio>
#include <typeinfo>
using namespace std;

class A
{
public:
	int m_a;

	A(int i = 0) :
		m_a(i){}

	virtual void func() {}
};

class B : public A
{
public:
	int m_b;

	B(int i = 0, int j = 0) :
		A(j),
		m_b(i)
	{}
};

template <typename T1, typename T2>
bool isSame(T1 a, T2 b)
{
	if (typeid(a) == typeid(b))
	{
		return true;
	}
	return false;
}

template <typename T1>
bool isInt(T1 a)
{
	if (typeid(a) == typeid(int))
	{
		return true;
	}
	return false;
}

int t1()
{
	int i = 0, j = 0;
	A a(3);
	char c = 0;

	cout << isSame(i, c) << endl;

	return 0;
}


int t2()
{
	double d = 1.333;

	int i = static_cast<int>(d);

	cout << i << endl;

	A a(3);
	B b(5, 6);

	//A * pa = static_cast<A *>(&b);
	//B * pb = static_cast<B *>(&a);

	A * pa = dynamic_cast<A *>(&b);
	B * pb = dynamic_cast<B *>(pa);

	cout << pb->m_b << endl;

	return 0;
}

int test(int i)
{
	cout << "testfunc" << i << endl;
	return 0;
}
//RFID

typedef int(*FUNC)();

int t3()
{
	int i;
	double d = 2.22;
	double * pd = &d;
	
	i = reinterpret_cast<int>(pd);

	//printf("0x%p\n", pd);
	//printf("0x%08X\n", i);

	double * pd2 = reinterpret_cast<double *>(i);

	cout << *pd2 << endl;

	FUNC f;
	
	f = reinterpret_cast<FUNC>(test);

	f();
	return 0;
}

int t4()
{
	int i = 8;
	const int * pi = &i;

	int * pi2 = const_cast<int *>(pi);

	*pi2 = 6;

	//printf("&i = %p\npi = %p\npi2 = %p\n", &i, pi, pi2);
	//printf("%d %d\n", i, *pi2);

	const int * pi3 = const_cast<const int *>(pi2);

	//*pi3 = 9;

	return 0;
}

class TestBase1
{
public:
	int m_a;
};

class TestBase2
{
public:
	int m_b;
};

class Test : public TestBase1, public TestBase2
{
public:
	int m_c;
};

int main()
{
	Test t;

	TestBase2 * tb1 = static_cast<TestBase2 *>(&t);
	TestBase2 * tb2 = reinterpret_cast<TestBase2 *>(&t);

	printf("&t  = %p\n", &t);
	printf("tb1 = %p\ntb2 = %p\n", tb1, tb2);
	return 0;
}
