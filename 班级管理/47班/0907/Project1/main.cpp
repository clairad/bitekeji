#include <iostream>
#include <typeinfo>
using namespace std;

template <class T>
void swapArgs(T &a, T &b)
{
	T tmp;

	//cout << typeid(tmp).name() << endl;
	tmp = a;
	a = b;
	b = tmp;
}

void swapArgs(int & a, int & b)
{
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}

template <typename T>
int findArgs(T * src, size_t n, T f)
{
	int i;
	for (i = 0; i < n; i++)
	{
		if (src[i] == f)
		{
			return i;
		}
	}
	return -1;
}

template <typename T>
T add(T a, T b)
{
	return a + b;
}

template <typename T1, typename T2>
T1 add(T1 a, T2 b)
{
	return a + b;
}

int add(int a, int b)
{
	return a + b;
}

int main1()
{
	cout << add(2, 'a') << endl;
	
	int ia = 5, ib = 7;
	double da = 3.14, db = 1.618;

	swapArgs<int>(ia, ib);
	cout << ia << ' ' << ib << endl;

	swapArgs(da, db);
	cout << da << ' ' << db << endl;

	double arr[] = { 1, 2, 3, 4, 5, 6, 7 };

	cout << findArgs(arr, 7, 5.0);
	return 0;
}