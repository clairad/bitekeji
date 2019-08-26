#include <iostream>
using namespace std;

void func(int &a, int &b)
{
	int tmp;

	tmp = a;
	a = b;
	b = tmp;
}

int _main()
{
	const int a = 10;
	const int & ra = a;
	double b = 1.23;
	const double &rb = b;

	/*int ming = 5;
	int &xiaoming = ming;

	cout << &ming << endl;
	cout << &xiaoming << endl;
	cout << xiaoming << endl;

	int a = 5, b = 6;;

	func(a, b);

	printf("%d %d\n", a, b);*/

	return 0;
}