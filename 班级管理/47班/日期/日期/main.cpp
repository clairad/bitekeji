#include "date.h"
#include <stdlib.h>

int _main()
{
	/*Date * pd1 = (Date *)malloc(sizeof(Date));
	//只是分配空间
	Date * pd2 = (Date *)operator new(sizeof(Date));
	//分配空间，失败会调用处理方式或者抛异常
	Date * pd3 = new Date(1999, 12, 20);
	//在operator new的基础上调用了构造函数

	Date * pd = new Date[3]{Date(1999, 12, 20), Date(2000, 12, 20), Date(2001, 12, 20)};


	cout << pd[0] << endl;
	cout << pd[2] << endl;

	delete[] pd;*/


	char * pa = (char *)malloc(1024);
	size_t size = 0;

	Date * pd = new(pa + size)Date(2015, 2, 22);

	size += sizeof(Date);

	Date * pd2 = new(pa + size)Date(2015, 2, 22);

	cout << (void *)pa << endl << pd << endl << pd2;
	return 0;
}


class HeapOnly{
	int m_a;

	HeapOnly() :
		m_a(0)
	{

	}
public:
	static HeapOnly * createObject();
};

HeapOnly * HeapOnly::createObject()
{
	HeapOnly * ho = new HeapOnly;
	return ho;
}

int main()
{
	Date a(1, 2, 3);

	return 0;
}