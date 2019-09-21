#pragma once
#include <string>
#include <iostream>
#include <cstring>
using namespace std;
#define NUMSIZE 10000

class HighAcc
{
	char m_data[NUMSIZE];
	size_t m_size;
public:
	HighAcc(string s):
		m_size(s.size())
	{
		memset(m_data, 0, NUMSIZE);
		string::reverse_iterator i;
		int j = 0;
		for (i = s.rbegin(); i != s.rend(); i++)
		{
			m_data[j] = *i - '0';
			j++;
		}
	}

	HighAcc() :
		m_size(1)
	{
		memset(m_data, 0, NUMSIZE);
	}

	HighAcc operator + (const HighAcc &s) const
	{
		HighAcc res;
		size_t maxsize = m_size > s.m_size ? m_size : s.m_size;
		int i;
		int tmp;

		for (i = 0; i < maxsize; i++)
		{
			tmp = m_data[i] + s.m_data[i] + res.m_data[i];
			res.m_data[i] = tmp % 10;
			res.m_data[i + 1] = tmp / 10;
		}

		res.m_size = maxsize + res.m_data[i];
		return res;
	}

	HighAcc operator * (const HighAcc &s) const
	{
		HighAcc res;
		int i, j, tmp;

		if (m_data[0] == 0 && m_size == 1 ||
			s.m_data[0] == 0 && s.m_size == 1)
		{
			return res;
		}

		for (i = 0; i < m_size; i++)
		{
			for (j = 0; j < s.m_size; j++)
			{
				tmp = m_data[i] * s.m_data[j] + res.m_data[i + j];
				res.m_data[i + j] = tmp % 10;
				res.m_data[i + j + 1] += tmp / 10;
			}
		}

		res.m_size = m_size + s.m_size - !res.m_data[i + j - 1];
		return res;
	}

	operator string()
	{
		string s;
		int i;

		for (i = m_size - 1; i >= 0; i--)
		{
			s.push_back(m_data[i] + '0');
		}
		return s;
	}
};