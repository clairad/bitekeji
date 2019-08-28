#include <iostream>
using namespace std; 

class A2 {
	char a;
	char b;
	char c;
};

class A1{
	A2 a;
	char s;
};

class A3{
	A1 ss;
	char sss;
public:
	void test()
	{
		
	}
	
	void test2()
	{
		sss = 0;
	}
};

int main()
{
	cout << sizeof(A1) << endl;
	cout << sizeof(A2) << endl;
	cout << sizeof(A3) << endl;
	
	A3 * t = NULL;
	t->test();
	t->test2();
	return 0;
}
