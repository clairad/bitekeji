#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

void filetest()
{
	ifstream ifs("1.txt");
	char str[20];

	ifs.getline(str, 19);

	cout << str;

	ifs.close();
}

void stringtest()
{
	ostringstream oss;

	oss << "hello,world!";

	//roll作业：stringstream的操作方式
}

int main()
{
	//stringtest();

	cerr << "error";

	return 0;
}