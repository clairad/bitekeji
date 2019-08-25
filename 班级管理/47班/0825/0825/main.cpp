#include <iostream>
using namespace std;
#include "t1.h"
using namespace t1;


namespace test
{
	namespace n1
	{
		int add(int a, int b)
		{
			std::cout << "1\n";
			return a + b;
		}
	}

	namespace n2
	{
		int add(int a, int b)
		{
			cout << "2\n";
			return a + b;
		}
	}
}

namespace n2
{
	int add(int a, int b)
	{
		cout << "3\n";
		return a + b;
	}
}

namespace n2
{
	int sub(int a, int b)
	{
		cout << "4\n";
		return a - b;
	}
}

int add(int a, int b)
{
	return a + b;
}
/*
int main()
{
	cout << t1::add(2, 3);
	return 0;
}
*/