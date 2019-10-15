#include <iostream>
#include <stack>
#include <vector>
#include <list>
#include <queue>
#include "mstack.h"
using namespace std;
/*
template<class T, class Container = deque<T>>
class stack
{

};*/

class test
{
	int m_data[10];
	int m_size;
public:
	test() :
		m_size(0)
	{}

	void push_back(int x)
	{
		m_data[m_size] = x;
		m_size++;
	}

	void pop_back()
	{
		m_size--;
	}

	int & front()
	{
		return m_data[0];
	}

	int & back()
	{
		return m_data[m_size - 1];
	}

	int size()
	{
		return m_size;
	}
};



int t1()
{
	queue<int, list<int>> s;

	s.push(1);
	s.push(2);
	s.push(3);

	cout << s.front() << endl;
	s.pop();
	cout << s.front() << endl;
	s.pop();
	cout << s.front() << endl;
	s.pop();

	return 0;
}

int t2()
{
	priority_queue<int, deque<int>> pq;

	pq.push(5);
	pq.push(4);
	pq.push(2);
	pq.push(7);
	
	cout << pq.top() << endl;
	pq.pop();
	cout << pq.top() << endl;
	pq.pop();
	cout << pq.top() << endl;
	pq.pop();
	return 0;
}

int t3()
{
	wf::stack<int, test> s;

	s.push(1);
	s.push(2);
	s.push(3);

	cout << s.top() << endl;
	s.pop();
	cout << s.top() << endl;
	s.pop();
	cout << s.top() << endl;
	s.pop();

	return 0;
}

class Func{
public:
	int operator()(int a, int b)
	{
		return a + b;
	}
};

int main()
{
	int a = 3, b = 4;
	Func f;
	cout << f(a, b);

	return 0;
}