#include <deque>
#include <queue>
#include <iostream>
#include <functional>
using namespace std;

int t1()
{
	deque<int> d;

	d.push_back(1);
	d.push_back(2);
	d.push_back(3);
	d.push_front(-1);

	deque<int>::iterator di = d.begin();

	cout << di[2] << endl;

	return 0;
}

int main()
{
	vector<int> v{ 1, 4, 2, 5, 7, 3, 8, 10 };
	priority_queue<int> q1;
	vector<int> v2;

	for (auto & i : v)
	{
		q1.push(i);
	}

	while (!q1.empty())
	{
		v2.push_back(q1.top());
		q1.pop();
	}

	for (auto & i : v2)
	{
		cout << i << endl;
	}


	return 0;
}