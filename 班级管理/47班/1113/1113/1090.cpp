#include <iostream>
#include <map>
#include <set>
#include <functional>
using namespace std;

int luogu1090()
{
	int n;
	cin >> n;

	multiset<int> data;
	multiset<int>::iterator is;
	int sum = 0;
	int i;
	int tmp;
	for (i = 0; i < n; i++)
	{
		cin >> tmp;
		data.insert(tmp);
	}

	while (data.size() > 1)
	{
		tmp = 0;
		is = data.begin();
		tmp += *is;
		data.erase(is);

		is = data.begin();
		tmp += *is;
		data.erase(is);

		data.insert(tmp);
		sum += tmp;
	}

	cout << sum;
	return 0;
}