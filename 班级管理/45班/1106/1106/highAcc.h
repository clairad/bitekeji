#pragma once
#include <string.h>
#include <iostream>
using namespace std;

class HighAcc
{
	char m_num[4000];
	size_t m_size;
public:

	HighAcc():
		m_size(1)
	{
		memset(m_num, 0, 2000);
	}

	HighAcc(const char * str):
		m_size(strlen(str))
	{
		memset(m_num, 0, 2000);
		int i;
		for (i = 0; i < m_size; i++)
		{
			m_num[i] = str[m_size - 1 - i] - '0';
		}
	}

	HighAcc operator + (const HighAcc & o) const
	{
		HighAcc res;

		int i;
		int tmp;
		int bigger = m_size > o.m_size ? m_size : o.m_size;
		for (i = 0; i < bigger; i++)
		{
			tmp = m_num[i] + o.m_num[i] + res.m_num[i];
			res.m_num[i] = tmp % 10;
			res.m_num[i + 1] = tmp / 10;
		}

		res.m_size = bigger + res.m_num[i];
		return res;
	}

	HighAcc operator * (const HighAcc & o) const
	{
		HighAcc res;

		if (m_size == 1 && m_num[0] == 0 ||
			o.m_size == 1 && o.m_num[0] == 0)
		{
			return res;
		}

		int i, j;
		int tmp;
		for (i = 0; i < m_size; i++)
		{
			for (j = 0; j < o.m_size; j++)
			{
				tmp = m_num[i] * o.m_num[j] + res.m_num[i + j];
				res.m_num[i + j] = tmp % 10;
				res.m_num[i + j + 1] += tmp / 10;
			}
		}

		res.m_size = m_size + o.m_size - !res.m_num[i + j - 1];
		return res;
	}

	friend ostream & operator << (ostream &os, const HighAcc & o)
	{
		int i;
		for (i = o.m_size - 1; i >= 0; i--)
		{
			os << (int)o.m_num[i];
		}
		return os;
	}
};