#include <iostream>
#include "seqlist.h"
#include <vector>
using namespace std;

template <class T>
class Test{
	T m_a;
public:
	Test(T s = 0) :
		m_a(s)
	{

	}

	void setData(T s);

	void showData()
	{
		cout << m_a << endl;
	}
};

template <class T>
void Test<T>::setData(T s)
{
	m_a = s;
}

int main()
{
	/*Test<int> a(6);
	a.setData(8);
	a.showData();*/

	/*SeqList<double> sl(10);

	int i;
	for (i = 0; i < sl.size(); i++)
	{
		sl[i] = (i + 1) * 0.15;
	}

	sl.pop_back();

	for (i = 0; i < sl.size(); i++)
	{
		cout << sl[i] << endl;
	}*/

	vector<double> v;
	
	int i;
	for (i = 0; i < 10; i++)
	{
		v.push_back(i + 1);
	}

	v.pop_back();

	for (i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}
	return 0;
}