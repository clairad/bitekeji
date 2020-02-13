#include <iostream>
using namespace std;

void outOfMem()
{
	cerr << "ÄÚ´æÉêÇëÊ§°Ü" << endl;
	//throw bad_alloc();
}

int main()
{
	set_new_handler(outOfMem);

	try{
		int *ptest1 = new int[100000000];
		int *ptest2 = new int[100000000];
		int *ptest3 = new int[100000000];
		int *ptest4 = new int[100000000];
		int *ptest5 = new int[100000000];
		int *ptest6 = new int[100000000];
		int *ptest7 = new int[100000000];
		int *ptest8 = new int[100000000];
	}
	catch (bad_alloc &bc)
	{
		cout << "bad alloc error!" << endl;
		cout << bc.what() << endl;
	}

	return 0;
}