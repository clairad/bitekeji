#include <iostream>
using namespace std;

class Test
{
	int m_a;
public:
	explicit Test(int a = 0) :
		m_a(a)
	{}

	void show()
	{
		cout << m_a << endl;
	}
};

int main()
{
	volatile const int a = 4;
	
	int * p = const_cast<int *>(&a);

	*p = 6;

	cout << a + 5 << endl;
	return 0;
}