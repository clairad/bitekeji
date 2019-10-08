#include <stack>
#include <queue>
#include <iostream>
using namespace std;

class MinStack {
	stack<int> m_data;
	stack<int> m_min;
public:
	/** initialize your data structure here. */
	MinStack() {

	}

	void push(int x) {
		m_data.push(x);

		if (m_min.empty() || m_min.top() > x)
		{
			m_min.push(x);
		}
	}

	void pop() {
		if (m_data.top() == m_min.top())
		{
			m_min.pop();
		}

		m_data.pop();
	}

	int top() {
		return m_data.top();
	}

	int getMin() {
		return m_min.top();
	}
};

class queueStack
{
	queue<int> m_qu1;
public:
	queueStack()
	{

	}

	void push(int x)
	{
		m_qu1.push(x);
	}

	void pop()
	{
		queue<int> m_qu2;
		while (m_qu1.size() > 1)
		{
			m_qu2.push(m_qu1.front());
			m_qu1.pop();
		}
		m_qu1 = m_qu2;
	}

	int top()
	{
		queue<int> m_qu2;
		while (m_qu1.size() > 1)
		{
			m_qu2.push(m_qu1.front());
			m_qu1.pop();
		}
		int tmp = m_qu1.front();
		m_qu2.push(m_qu1.front());
		m_qu1 = m_qu2;
		return tmp;
	}
};

int p1()
{
	queueStack qs;

	qs.push(1);
	qs.push(2);
	qs.push(3);
	qs.push(4);

	cout << qs.top() << endl;
	qs.pop();
	cout << qs.top() << endl;
	qs.pop();
	cout << qs.top() << endl;
	qs.pop();
	cout << qs.top() << endl;
	qs.pop();

	return 0;
}