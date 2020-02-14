#include <iostream>
#include <typeinfo>
#include <vector>
#include <map>
using namespace std;

//列表初始化
#if 0 //容器、动态内存分配

int main()
{
	map < int, int > m {{ 2, 2 }, { 1, 4 }, { 5, 8 }, { 6, 2 }};

	int * pi = new int[5] {1, 2, 3, 4, 5};

	for (auto & e : m)
	{
		cout << e.first << ' ' << e.second << endl;
	}

	for (int i = 0; i < 5; i++)
	{
		cout << pi[i] << endl;
	}

	delete[]pi;
	return 0;
}
#elif 0 //调用构造函数

class Test
{
	int m_a;
	int m_b;
public:
	Test(int a = 0, int b = 0) :
		m_a(a),
		m_b(b)
	{}

	void show()
	{
		cout << m_a << ' ' << m_b << endl;
	}
};

int main()
{
	Test t[3]{ { 2, 5 }, { 4, 7 }, { 5, 3 } };

	t[0].show();
	t[1].show();
	t[2].show();
	return 0;
}

#elif 0 //多个对象初始化

class Test
{
	int m_data[100];
	int m_size;
public:
	Test(initializer_list<int> l)
	{
		int * tmp = m_data;
		for (auto & e : l)
		{
			*tmp = e;
			tmp++;
		}

		m_size = l.size();
	}

	void show()
	{
		for (int i = 0; i < m_size; i++)
		{
			cout << m_data[i] << ' ';
		}
		cout << endl;
	}
};

int main()
{
	Test t{ 1, 2, 3, 4, 5 };

	t.show();
	return 0;
}

/*
	vector(initializer_list<T> l)
	{
		reserve(l.size());

		for (auto & e : l)
		{
			*m_finish = e;
			m_finish++;
		}
	}

	详见0922v
*/

#endif

#if 0 //decltype

void * getmemory(size_t size)
{
	return malloc(size);
}

int main()
{
	int a = 4;
	double b = 3.14;
	char c = '7';

	decltype(a + b + c) d;

	cout << typeid(d).name() << endl;

	cout << typeid(decltype(getmemory)).name() << endl;
	cout << typeid(decltype(getmemory(0))).name() << endl;
	return 0;
}

#endif

