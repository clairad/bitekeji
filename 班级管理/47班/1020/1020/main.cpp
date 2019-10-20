#include <iostream>
using namespace std;

template < class T, size_t N = 10 >
class Array
{
	T m_data[N];
public:
	Array()
	{
		cout << N;
	}
};

int test()
{
	const int i = 100;
	Array<int, i> a;

	return 0;
}