#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void mul2(int & val) //Ò»ÔªÎ½´Ê
{
	val *= 2;
}

/*
void for_each_m(vector<int>::iterator s, vector<int>::iterator e, void(*fun)(int &))
{
	for (; s != e; s++)
	{
		fun(*s);
	}
}
*/

class Mul2
{
public:
	void operator()(int & s)
	{
		s *= 2;
	}
};


int main2()
{
	vector<int> v{ 1, 2, 3, 4, 5 };

	Mul2 m2;
	for_each(v.begin(), v.end(), m2);

	for (auto & e : v)
	{
		cout << e << endl;
	}


	return 0;
}