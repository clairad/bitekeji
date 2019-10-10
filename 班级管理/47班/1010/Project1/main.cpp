#include <iostream>
#include <stack>
using namespace std;

class stackQueue
{
	stack<int> m_s1;
	stack<int> m_s2;
public:
	stackQueue()
	{

	}

	void push(int i)
	{
		m_s1.push(i);
	}

	void pop()
	{
		while (m_s1.size() > 1)
		{
			m_s2.push(m_s1.top());
			m_s1.pop();
		}
		m_s1.pop();

		while (!m_s2.empty())
		{
			m_s1.push(m_s2.top());
			m_s2.pop();
		}
	}

	int front()
	{
		while (m_s1.size() > 1)
		{
			m_s2.push(m_s1.top());
			m_s1.pop();
		}
		int tmp = m_s1.top();

		while (!m_s2.empty())
		{
			m_s1.push(m_s2.top());
			m_s2.pop();
		}

		return tmp;
	}

	int back()
	{
		return m_s1.top();
	}
};

int t1()
{
	stackQueue sq;

	sq.push(2);
	sq.push(3);
	sq.push(4);

	cout << sq.front() << endl;
	sq.pop();
	cout << sq.front() << endl;
	sq.pop();
	cout << sq.front() << endl;
	sq.pop();

	return 0;
}
