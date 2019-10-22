#include <iostream>
#include <sstream>
#include <string>
using namespace std;

void T1()
{
	stringstream ss;
	float s;

	ss << 1.23;

	ss >> s;

	cout << s;
}

