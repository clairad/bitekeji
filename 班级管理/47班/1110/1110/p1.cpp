#include <iostream>
#include <string>
using namespace std;

int g_blbitmap = 0;
int g_slbitmap = 0;

void setbit(char ch)
{
	if (ch <= 'Z' && ch >= 'A')
	{
		g_blbitmap |= 1 << ch - 'A';
	}
	else
	{
		g_slbitmap |= 1 << ch - 'a';
	}
}

bool find(char ch)
{
	if (ch <= 'Z' && ch >= 'A')
	{
		return (g_blbitmap >> ch - 'A') & 1;
	}
	else
	{
		return (g_slbitmap >> ch - 'a') & 1;
	}
}


int p1()
{
	char tmp[101] = { 0 };

	cin >> tmp;
	string src(tmp);
	string dst;

	for (auto & ch : src)
	{
		if (!find(ch))
		{
			dst.push_back(ch);
			setbit(ch);
		}
	}
	
	cout << dst;

	return 0;
}