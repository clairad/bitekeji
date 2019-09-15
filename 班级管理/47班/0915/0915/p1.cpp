#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void reverseString(string &s)
{
	int i, j;

	for (i = 0, j = s.size() - 1; i < j; i++, j--)
	{
		swap(s[i], s[j]);
	}
}

int test1()
{
	string s1("ikun");

	reverseString(s1);

	cout << s1;
	return 0;
}

int firstUniqChar(string s)
{
	int count[26] = { 0 };

	for (auto & ch : s)
	{
		count[ch - 'a']++;
	}

	/*int j = 0;
	for (auto & i : count)
	{
		cout << (char)('a' + j++) << ' ' << i << endl;
 	}*/

	for (int i = 0; i < s.size(); i++)
	{
		if (count[s[i] - 'a'] == 1)
		{
			return i;
		}
	}
	return -1;
}

int test2()
{
	string s;

	cin >> s;

	cout << firstUniqChar(s);
	return 0;
}

bool isLetterOrNumber(char ch)
{
	return (ch >= 'a' && ch <= 'z') ||
		   (ch >= 'A' && ch <= 'Z') ||
		   (ch >= '0' && ch <= '9');
}

bool isSame(char a, char b)
{
	return a == b ||
(a | 1 << 5) == (b | 1 << 5);
}

bool isPalindrome(string s)
{
	string tmp;

	for (auto & ch : s)
	{
		if (isLetterOrNumber(ch))
		{
			tmp.push_back(ch);
		}
	}

	int i, j;
	for (i = 0, j = tmp.size() - 1; i < j; i++, j--)
	{
		if (!isSame(tmp[i], tmp[j]))
		{
			return false;
		}
	}
	return true;
}

int test4()
{
	string s("A man, a plan, a canal : Panama");
	//string s("asd");

	cout << isPalindrome(s);
	return 0;
}