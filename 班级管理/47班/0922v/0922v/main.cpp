#include <iostream>
#include "Vector.h"
using namespace std;

int main()
{
	int a[] = { 2, 3, 4, 5 };
	wf::vector<int> v2(a, a + 4);
	wf::vector<int> v(v2.begin(), v2.end());

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}

	//cout << v.size();
	return 0;
}