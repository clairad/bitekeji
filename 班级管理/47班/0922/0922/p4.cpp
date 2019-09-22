#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findMaxTimesNum(const vector<int>& v)
{
	int icount = 1;
	int num = v[0];

	int i;
	for (i = 1; i < v.size(); i++)
	{
		if (v[i] == v[i - 1])
		{
			icount++;
		}
		else
		{
			if (icount <= 1)
			{ 
				num = v[i];
			}
			else
			{
				icount--;
			}
		}
	}

	if (v.size() / 2 < count(v.begin(), v.end(), num))
	{
		return num;
	}
	return 0;
}

int p4()
{
	int nums[9] = { 2, 2, 3, 8, 5, 2, 3, 3, 2 };
	vector<int> v;
	v.insert(v.begin(), nums, nums + 9);

	cout << findMaxTimesNum(v);
	return 0;
}