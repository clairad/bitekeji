#include <iostream>
using namespace std;

template <class T>
class smart_ptr
{
	T * m_ptr;
	int * m_pcount;
public:
	smart_ptr(const smart_ptr & o)
	{
		m_ptr = o.m_ptr;
		m_pcount = o.m_pcount;
		(*m_pcount)++;
	}

	smart_ptr & operator = (const smart_ptr & o)
	{
		destroy();

		m_ptr = o.m_ptr;
		m_pcount = o.m_pcount;
		(*m_pcount)++;

		return *this;
	}

	smart_ptr(T * ptr = nullptr) :
		m_ptr(ptr),
		m_pcount(new int(1))
	{

	}

	~smart_ptr()
	{
		destroy();
	}

	void destroy()
	{
		if (*m_pcount > 1)
		{
			(*m_pcount)--;
		}
		else if (m_ptr)
		{
			delete[] m_ptr;
			delete m_pcount;
			m_ptr = nullptr;
		}
	}

	T &operator *()
	{
		return *m_ptr;
	}

	T *operator ->()
	{
		return m_ptr;
	}

	T &operator [](int i)
	{
		return m_ptr[i];
	}

	int use_count()
	{
		return *m_pcount;
	}
};

class Test
{
public:
	int m_a;
};

int main1()
{
	smart_ptr<Test> sp(new Test);

	sp->m_a = 5;

	//cout << sp->m_a;

	smart_ptr<Test> sp2(sp);

	sp2->m_a = 6;

	cout << sp->m_a << endl;

	return 0;
}

struct ListNodes
{
	int _data;
	smart_ptr<ListNodes> _prev;
	smart_ptr<ListNodes> _next;

	~ListNodes(){ cout << "~ListNode()" << endl; }
};

int main11()
{
	smart_ptr<ListNodes> node1(new ListNodes);
	smart_ptr<ListNodes> node2(new ListNodes);
	cout << node1.use_count() << endl;
	cout << node2.use_count() << endl;

	node1->_next = node2;
	node2->_prev = node1;

	cout << node1.use_count() << endl;
	cout << node2.use_count() << endl;

	return 0;
}