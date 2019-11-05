#include <iostream>
using namespace std;
/*
template <class T>
class smart_ptr
{
	T * m_ptr;
public:
	smart_ptr(const smart_ptr & o) = delete;
	smart_ptr & operator = (const smart_ptr & o) = delete;

	smart_ptr(T * ptr = nullptr) :
		m_ptr(ptr)
	{

	}

	~smart_ptr()
	{
		if (m_ptr)
		{
			delete [] m_ptr;
			m_ptr = nullptr;
		}
	}

	T &operator *()
	{
		return *m_ptr;
	}

	T *operator ->()
	{
		return m_ptr;
	}

	T &operator [](int i)
	{
		return m_ptr[i];
	}
};

class Test
{
public:
	int m_a;
};

int main_()
{
	smart_ptr<Test> sp(new Test);

	sp->m_a = 5;

	cout << sp->m_a;

	smart_ptr<Test> sp2;

	return 0;
}

*/


/*C”Ô—‘÷∏’Îµƒ»±œ›
int main()
{
	int * pi = (int *)malloc(5 * sizeof(int));
	if (pi == NULL)
	{
		return 2;
	}

	int ret;
	ret = funcA();
	if (ret != OK)
	{
		delete[]pi;
		return 1;
	}

	int * pi2 = (int *)malloc(5 * sizeof(int));
	if (pi2 == NULL)
	{
		delete[]pi;
		return 2;
	}
	ret = funcB();
	if (ret != OK)
	{
		delete[]pi;
		delete[]pi2;
		return 1;
	}

	delete[]pi;
	delete[]pi2;
	return 0;
}
*/