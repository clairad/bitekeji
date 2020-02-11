#include <iostream>
using namespace std;

#if 0 //namespace

namespace wf{
	int a;
};

namespace wf2{
	int a;
};

using namespace wf;
using namespace wf2;

int func(int a, int b = 0);
int func(int a);

int main()
{
	a = 10;

	return 0;
}
#endif

#if 0 //ÒýÓÃ

int main()
{
	int a;
	int &o = a;
	return 0;
}

#endif

#if 0 //·¶Î§for
#include <vector>

int main()
{
	int a[10];
	for (int i = 0; i < 10; i++)
	{
		a[i] = i;
	}

	for (auto &e : a)
	{
		e = 8;
	}

	vector<int> v(10);

	for (vector<int>::iterator i = v.begin(); i != v.end(); i++)
	{
		*i = 7;
	}

	for (auto & e : v)
	{
		e = 8;
	}
	return 0;
}

#endif

#if 0

class test{

public:
	int m_a;

	test(int a = 0) :
		m_a(a)
	{}

	int func1(int a) const
	{
		cout << m_a << ' ' << a << endl;
	}

	int func2()
	{
		cout << m_a << endl;
	}
};

int main()
{
	const test t(5);
	t.func1(5);
	//t.func2();
	return 0;
}
#endif

#if 0

class o{
	int a;
	class i{
		int a;
	};
};

#endif

#if 0

template<typename T1, typename T2>
void func(T1 a, T2 b)
{
	a = 5;
}

void func(int a, char b)
{
	a = 5;
}

void func(int a, int b)
{
	a = 5;
}

#endif

#if 1

int main()
{
	const int a = 7;
	int * s = const_cast<int *>(&a);

	*s = 5;
	cout << *s << ' ' << a;

	return 0;
}
#endif
