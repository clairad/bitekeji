#include <iostream>
using namespace std;

int d6p1()
{
	int a, b;

	cin >> a >> b;

	int x, y;

	int suba = 4 - (a % 4 ? a % 4 : 4);
	int subb = 4 - (b % 4 ? b % 4 : 4);
	x = a + suba;
	y = b + subb;

	int sum = x * y / 2;

	sum -= suba * (x / 2) + subb * (y / 2);

	if (suba == 0 && subb == 0)
	{
		//do nothing
	}
	else if (suba == 1 && subb == 1)
	{
		sum++;
	}
	else if (suba == 1 || subb == 1)
	{
		sum += 2;
	}
	else if (suba == 3 && subb == 3)
	{
		sum += 5;
	}
	else
	{
		sum += 4;
	}

	cout << sum;

	return 0;
}