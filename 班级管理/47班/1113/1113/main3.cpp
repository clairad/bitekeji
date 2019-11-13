#include <iostream>
#include <map>
#include <set>
#include <string>
#include <functional>
using namespace std;
#define ARRSIZE(a) (sizeof(a) / sizeof(a[0])) 

int main3()
{
	map<char, int> m;

	string s;

	cin >> s;

	for (auto & i : s)
	{
		m[i]++;
	}

	for (auto & i : m)
	{
		cout << i.first << ' ' << i.second << endl;
	}

	return 0;
}