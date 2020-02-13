#pragma once
#include <vector>
using namespace std;

namespace wf{

class bitmap
{
	vector<int> m_bit;
	size_t m_bitcount;
public:
	bitmap(size_t bitc) :
		m_bit(bitc / 32 + 1),
		m_bitcount(bitc)
	{}

	void set(size_t pos)
	{
		if (pos > m_bitcount)
		{
			return;
		}

		size_t index = pos / 32;
		size_t bits = pos % 32;

		m_bit[index] |= 1u << bits;
	}

	void reset(size_t pos)
	{
		if (pos > m_bitcount)
		{
			return;
		}

		size_t index = pos / 32;
		size_t bits = pos % 32;

		m_bit[index] &= ~(1u << bits);
	}

	bool get(size_t pos)
	{
		if (pos > m_bitcount)
		{
			return;
		}

		size_t index = pos / 32;
		size_t bits = pos % 32;

		return m_bit[index] >> bits & 1;
	}

	size_t size()
	{
		return m_bitcount;
	}

	size_t count()
	{
		const char * pCount = "\0\1\1\2\1\2\2\3\1\2\2\3\2\3\3\4";
							//  0 1 2 3 4 5 6 7 8 9 a b c d e f

		size_t size = m_bit.size();
		size_t count = 0;
		size_t i;
		for (i = 0; i < size; i++)
		{
			int value = m_bit[i];
			int j;
			for (j = 0; j < sizeof(m_bit[0]); j++, value >>= 8)
			{
				char c = value;

				count += pCount[c & 0x0f];
				c >> 4;
				count += pCount[c & 0x0f];
			}
		}
	}
};

};