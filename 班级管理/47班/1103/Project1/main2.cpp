#include <iostream>
#include <memory>
using namespace std;

class Test
{
public:
	int m_a;
};

int main2()
{
	auto_ptr<int> ap(new int);
	auto_ptr<Test> apt(new Test);

	*ap = 5;
	apt->m_a = 6;

	cout << *ap << ' ' << apt->m_a << endl;

	auto_ptr<int> ap2 = ap;

	cout << *ap2 << ' ' << apt->m_a << endl;
	return 0;
}