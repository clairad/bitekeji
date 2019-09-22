#include <iostream>
#include <vector>
using namespace std;

int main1()
{
	vector<int> v;

	for (int i = 1; i <= 10; i++)
	{
		v.push_back(i);
	}

#if 0 //insert
	v.insert(v.begin() + 5, 20);

#elif 0
	v.insert(v.begin() + 5, 3, 20);

#else
	int a[5] = { 10, 20, 30, 40, 50 };
	v.insert(v.begin() + 5, a + 1, a + 2);

#endif

#if 1 //erase
	v.erase(v.begin() + 5);

#else
	v.erase(v.begin() + 5, v.end() - 3);

#endif

#if 0
	vector<int> v2;

	for (int i = 1; i <= 10; i++)
	{
		v2.push_back(i);
	}

	v.swap(v2);
#endif
#if 0
	vector<int>::iterator iv = v.begin() + 5;

	cout << *iv << endl;
	iv = v.erase(iv);
	cout << *iv << endl;
#endif

	for (auto iv = v.begin(); iv != v.end(); iv++)
	{
		if (*iv % 2 == 0)
		{
			iv = v.erase(iv);
			iv--;
		}
	}

	for (auto & i : v)
	{
		cout << i << ' ';
	}

	return 0;
}	

int _main()
{
	vector<int> v;

	v.push_back(1);
	vector<int>::iterator iv = v.begin();
	iv = v.insert(iv, 10, 6);

	cout << iv - v.begin() << endl;

	for (auto & i : v)
	{
		cout << i << ' ';
	}

	return 0;
}