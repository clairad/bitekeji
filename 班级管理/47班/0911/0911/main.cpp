#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <typeinfo>
using namespace std;

int __main()
{
	string s1;
	string s2("caixukun");
	string s3 = s2;
	string s4(5, '6');


	s1.push_back('1');
	s1.resize(100, 'n');
	cout << s1.size() << endl;
	s1.push_back('2');

	cout << s1 << endl;

	s1.resize(6);
	s1.push_back('3');
	cout << s1 << endl;

	/*s1.clear();
	cout << s1.capacity() << endl;
	cout << s1.size() << endl;*/

	for (auto & i : s1)
	{
		cout << i;
	}

	/*for (auto &i : s1)
	{
		printf("%d", i);
	}*/
	/*s4 += s3;
	s4 += "qiaobiluo";
	s4 += "zhangyixing";

	cout << s1 << endl
		 << s2 << endl
		 << s3 << endl
		 << s4 << endl;
		 
	cout << s1.length() << endl
		 << s2.length() << endl
		 << s3.length() << endl
		 << s4.length() << endl;

	cout << s1.capacity() << endl
		 << s2.capacity() << endl
		 << s3.capacity() << endl
		 << s4.capacity() << endl;

	cout << s4.empty() << endl;

	s4.clear();
	cout << s4.empty() << endl;
	cout << s4.size() << endl;*/
	return 0;
}
/*
char &opreator[](int i)
{
	return  m_d[i];
}*/


int _main()
{
	string s1("Hello");

	s1.resize(9);
	s1.push_back('a');

	cout << typeid(s1).name() << endl;
	cout << typeid(s1.c_str()).name() << endl;

	cout << s1.c_str() << endl;

	for (size_t i = 0; i < s1.size(); i++)
	{
		cout << s1[i];
	}
	cout << endl;

	for (auto i = s1.begin(); i != s1.end(); i++)
	{
		cout << *i;
	}
	cout << endl;

	for (auto & i : s1)
	{
		cout << i;
	}
	cout << endl << s1 << endl;
	return 0;
}

int main()
{
	string s1;
	string s2;

	s1 += "abc";
	s1 += "de\nf";
	s1 += "ghi";

	s1.append(2, 'c');

	return 0;
}