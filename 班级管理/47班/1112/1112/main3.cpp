#include <iostream>
#include <string>
#include <map>
using namespace std;

class Test
{
public:
	int m_a;

	Test(int a = 0):
		m_a(a){}

	bool operator<(const Test & it) const
	{
		return m_a < it.m_a;
	}

	bool operator>(const Test & it) const
	{
		return m_a > it.m_a;
	}

	bool operator<=(const Test & it) const
	{
		return m_a <= it.m_a;
	}

	bool operator>=(const Test & it) const
	{
		return m_a >= it.m_a;
	}

	bool operator==(const Test & it) const
	{
		return m_a == it.m_a;
	}

	bool operator!=(const Test & it) const
	{
		return m_a != it.m_a;
	}
};

int main()
{
	pair<Test, int> p;

	p.first = Test(5);
	p.second = 2;

	map<Test, int> m;

	m.insert(pair<Test, int>(Test(6), 5));
	m.insert(pair<Test, int>(Test(1), 4));
	m.insert(p);
	m.insert(pair<Test, int>(Test(8), 8));
	m.insert(pair<Test, int>(Test(9), 6));

	m.insert(pair<Test, int>(Test(5), 9));

	//map<int, int>::iterator mi = m.begin();

	for (auto & i : m)
	{
		cout << i.first.m_a << ' ' << i.second << endl;
	}

	//map<int, int>::iterator mi = m.find(4);

	//cout << mi->first << ' ' << mi->second << endl;
	return 0;
}