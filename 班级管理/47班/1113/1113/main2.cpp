#include <iostream>
#include <map>
#include <set>
#include <functional>
using namespace std;
#define ARRSIZE(a) (sizeof(a) / sizeof(a[0])) 

int main2()
{
	map<int, int, greater<int>> m;

	m.insert(pair<int, int>(1, 2));
	m.insert(pair<int, int>(3, 4));
	m.insert(pair<int, int>(5, 8));
	m.insert(pair<int, int>(8, 3));
	m.insert(pair<int, int>(4, 7));
	m.insert(pair<int, int>(2, 5));

	m[7]++;

	for (auto & i : m)
	{
		cout << i.first << ' ' << i.second << endl;
	}
	
	cout << m[6] << endl;

	m.erase(5);
	for (auto & i : m)
	{
		cout << i.first << ' ' << i.second << endl;
	}

	return 0;
}