#include <iostream>
using namespace std;

template< typename T >
void swapArgs(T & a, T & b)
{
	T tmp;

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

template<>
void swapArgs<int>(int & a, int & b)
{
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}

int main2()
{
	int a = 5;
	int b = 6;
	swapArgs(a, b);

	cout << a << ' ' << b << endl;
	return 0;
}