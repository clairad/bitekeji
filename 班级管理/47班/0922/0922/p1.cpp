#include <iostream>
#include <vector>
using namespace std;

int singleNumber(vector<int>& nums)
{
	int res = 0;
	for (auto &i : nums)
	{
		res ^= i;
	}
	return res;
}

int p1()
{
	int nums[11] = { 1, 5, 6, 3, 5, 2, 1, 8, 6, 3, 8 };
	vector<int> v;
	v.insert(v.begin(), nums, nums + 11);

	cout << singleNumber(v);
	return 0;
}