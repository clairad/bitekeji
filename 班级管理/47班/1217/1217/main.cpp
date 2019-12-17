#include <iostream>
#include "hashTable.h"
#include <unordered_map>
using namespace std;

int repeatedNTimes(vector<int>& A)
{
	unordered_map<int, int> um;
	int n = A.size() / 2;

	for (auto & e : A)
	{
		um[e]++;
	}

	for (auto & e : um)
	{
		if (e.second == n)
		{
			return e.first;
		}
	}
	return -1;
}

int test()
{
	vector<int> v{ 1, 3, 4, 2, 3, 3 };
	
	cout << repeatedNTimes(v);

	return 0;
}

int main1()
{
	wf::hashTable<int, int> ht;

	ht.insert(pair<int, int>(1, 5));
	ht.insert(pair<int, int>(2, 7));
	ht.insert(pair<int, int>(5, 6));
	ht.insert(pair<int, int>(6, 8));
	ht.insert(pair<int, int>(12, 9));
	ht.insert(pair<int, int>(16, 4));

	ht.erase(6);
	ht.erase(12);

	ht.insert(pair<int, int>(23, 11));
	ht.insert(pair<int, int>(27, 13));

	return 0;
}

int main()
{
	wf::hashTable<string, int, wf::dealString> ht;

	ht.insert(pair<string, int>("abc", 1));
	ht.insert(pair<string, int>("def", 2));
	ht.insert(pair<string, int>("ghi", 3));
	ht.insert(pair<string, int>("jkl", 4));


	return 0;
}