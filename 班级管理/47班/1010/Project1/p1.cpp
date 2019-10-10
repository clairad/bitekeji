#include <iostream>
#include <vector>
#include <stack>
using namespace std;

bool IsPopOrder(vector<int> pushV, vector<int> popV)
{
	stack<int> stmp;
	int i = 0;

	for (auto & vi : pushV)
	{
		stmp.push(vi);
		for (; !stmp.empty() && stmp.top() == popV[i]; i++)
		{ 
			stmp.pop();
		}
	}

	return stmp.empty();
}

int p1()
{
	vector<int> puv{ 1, 2, 3, 4, 5 };
	vector<int> pov{ 4, 5, 1, 2, 3 };

	cout << IsPopOrder(puv, pov);
	return 0;
}