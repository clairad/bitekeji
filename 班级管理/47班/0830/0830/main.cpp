#include <iostream>
using namespace std;

class Test2{
	
public:
	int b;

	explicit Test2(int a) :b(a)
	{
	}


	Test2(Test2 & t)
	{
		b = t.b;
	}

};

class Test{
public:
	int a = 5;
	const int i = 3;
	int &ri;
	Test2 t2;

	Test(int &a) : ri(a), t2(a)
	{
	}
};


int main1()
{
	int i = 8;
	int j = 9;
	Test2 a(i);
	Test2 b = a;
	Test2 c(j);

	c = b;

	cout << c.b << endl;

	return 0;
}