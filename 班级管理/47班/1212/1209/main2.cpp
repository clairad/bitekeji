#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
	unordered_map<int, int> um;
	um.insert(pair<int, int> (2, 5));
	um[3] = 6;
	um[4] = 7;
	um[1] = 9;
	um[30] = 18;

	for (auto &i : um)
	{
		cout << i.first << ' ' << i.second << endl;
	}

	unordered_map<int, int>::reverse_iterator umri;
	for (umri = um.rbegin(); umri != um.rend(); umri++)
	{
		cout << umri->first << ' ' << umri->second << endl;
	}

	cout << um.size() << endl;

	return 0;
}