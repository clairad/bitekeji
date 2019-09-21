#include <iostream>
#include <string>
#include "HighAcc.h"
using namespace std;

void reverseOneWord(string &s, int spos, int epos)
{
	int i, j;

	for (i = spos, j = epos - 1; i < j; i++, j--)
	{
		swap(s[i], s[j]);
	}
}

string reverseWords(string s)
{
	int spos = 0;
	int epos = s.find(' ');

	while (epos >= 0)
	{
		reverseOneWord(s, spos, epos);
		spos = epos + 1;
		epos = s.find(' ', spos);
	}

	reverseOneWord(s, spos, s.size());
	return s;
}

string multiply(string num1, string num2)
{
	HighAcc snum1(num1);
	HighAcc snum2(num2);

	return (string)(snum1 * snum2);
}

int _main()
{
	string s1("749162978439");
	string s2("0");

	HighAcc num1(s1);
	HighAcc num2(s2);

	cout << (string)(num1 * num2);


	//cout << reverseWords("This way is not fit me");

	return 0;
}