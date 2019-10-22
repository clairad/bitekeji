#include <iostream>
using namespace std;

class TBase1
{
public:
	static int m_s_i;
};

int TBase1::m_s_i = 10;


class TBase2 : public TBase1
{

};

class TBase3 : public TBase2
{

};

class TBase4 : public TBase3
{

};

int main()
{
	TBase3::m_s_i = 20;

	cout << TBase1::m_s_i;

	return 0;
}