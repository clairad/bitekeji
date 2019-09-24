#include <iostream>
#include "Vector.h"
using namespace std;

int main()
{
	int a[] = { 2, 3, 4, 5 };
	wf::vector<int> v2(a, a + 4);
	wf::vector<int> v(v2.begin(), v2.end());

	v.insert(v.begin() + 2, a + 1, a + 3);

	v.erase(v.begin() + 2, v.end() - 1);

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}

	//cout << v.size();
	return 0;
}