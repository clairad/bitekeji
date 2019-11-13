#include <iostream>
#include <map>
#include <set>
#include <functional>
using namespace std;
#define ARRSIZE(a) (sizeof(a) / sizeof(a[0])) 

int main1()
{
	int a[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 0, 1, 3, 5, 7, 9, 2, 4, 6, 8, 0 };
	multiset<int, greater<int>> ms(a, a + ARRSIZE(a));
	set<int, greater<int>> s(a, a + ARRSIZE(a));

	cout << ms.size() << endl;

	//ms.erase(3);

	for (auto & i : ms)
	{
		cout << i << ' ';
	}
	cout << endl;

	cout << ms.count(4) << endl;

	cout << s.size() << endl;

	for (auto & i : s)
	{
		cout << i << ' ';
	}
	cout << endl;

	return 0;
}