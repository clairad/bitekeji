#include <iostream>
#include <vector>
using namespace std;

class CSomething
{
	
	int a;
public:
	static int s;
	CSomething(){ s++; }

	CSomething(const CSomething &o){ s++; }

	CSomething(int a){ s++; }
};

int CSomething::s = 0;

int main()
{
	CSomething a();
	CSomething b(2);
	CSomething c[3];
	CSomething &ra = b;
	CSomething d = b;
	CSomething *pA = c;
	CSomething *p = new CSomething(4);

	return 0;
}

int main22()
{
	int n;
	int tmp;
	int presum = 0;
	int max = 0x80000000;
	int tmpmax = 0;

	cin >> n;

	int i;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		tmpmax = tmpmax >= 0 ? tmpmax + tmp : tmp;
		max = tmpmax > max ? tmpmax : max;
	}

	cout << max;
	return 0;
}