#include <iostream>
#include <memory>
using namespace std;

template <class T>
struct Freefunc
{
	void operator()(T * ptr)
	{
		cout << "freefunc" << endl;
		free(ptr);
	}
};

template <class T>
struct Deletefunc
{
	void operator()(T * ptr)
	{
		cout << "deletefunc" << endl;
		delete []ptr;
	}
};

template <class T>
struct Arrayfunc
{
	void operator()(T * ptr)
	{
		cout << "arrayfunc" << endl;
	}
};

int main()
{
	shared_ptr<int> sp((int *)malloc(sizeof(int)), Freefunc<int>());

	shared_ptr<int> sp2(new int, Deletefunc<int>());

	int arr[5];
	shared_ptr<int> sp3(arr, Arrayfunc<int>());
	return 0;
}