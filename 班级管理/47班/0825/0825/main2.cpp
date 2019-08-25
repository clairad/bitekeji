#include <iostream>
using namespace std;

void func(int a, int b, int c);

void func(int a, int b = 20, int c = 30)
{
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
}

void swapArgs(int * pa, int * pb)
{
	int tmp;

	tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}

void swapArgs(float * pa, float * pb)
{
	float tmp;

	tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}

int add(short a, short b)
{
	return a + b;
}

short add(short a, short b)
{
	return a + b;
}

int main()
{
	//func();
	func(2);
	func(3, 4);
	func(5, 6, 7);

	int a = 4, b = 7;
	float c = 3.14, d = 1.618;

	swapArgs(&a, &b);
	swapArgs(&c, &d);

	cout << a << " " << b << endl;
	cout << c << " " << d << endl;
	return 0;
}