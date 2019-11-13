#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

class Solution {
public:
	class Compare
	{
	public:
		bool operator()(const pair<string, int> & p1, const pair<string, int> & p2)
		{
			return p1.second > p2.second ||
				p1.second == p2.second && p1.first < p2.first;
		}
	};

	vector<string> topKFrequent(vector<string>& words, int k)
	{
		vector<string> vs(k);
		map<string, int> msi;

		for (auto &i : words)
		{
			msi[i]++;
		}

#if 0
		multiset<pair<string, int>, Compare> msp(msi.begin(), msi.end());

		int i;

		multiset<pair<string, int>, Compare>::iterator mspi = msp.begin();

		for (i = 0; i < k; i++)
		{
			vs[i] = mspi->first;
			mspi++;
		}
#else
		vector < pair<string, int > > vps(msi.begin(), msi.end());
		Compare cp;

		sort(vps.begin(), vps.end(), cp);

		int i;
		for (i = 0; i < k; i++)
		{
			vs[i] = vps[i].first;
		}
#endif

		return vs;
	}
};

int main()
{
	Solution s;
	vector < string > vs{"wang", "zhang", "li", "zhao", "liu", "zhang", "li", "zhao", "liu", "zhang"};

	vs = s.topKFrequent(vs, 5);

	for (auto &i : vs)
	{
		cout << i << endl;
	}

	return 0;
}