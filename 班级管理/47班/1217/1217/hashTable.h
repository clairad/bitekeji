#pragma once

#include <map>
#include <vector>
using namespace std;

namespace wf{

enum State{
	EMPTY,
	EXIST,
	DELETE
};

class dealInt
{
public:
	int operator()(int n)
	{
		return n;
	}
};

class dealString
{
public:
	int operator()(const string & n)
	{
		int sum = 0;
		int seed = 131;

		for (const char & c : n)
		{
			sum = sum * seed + c;
		}

		return sum & 0x7FFFFFFF;
	}
};

template<class K, class V, class SW = dealInt>
class hashTable
{
	struct elem
	{
		pair<K, V> m_val;
		State m_state;

		elem(const K & key = K(), const V & val = V(), State state = EMPTY):
			m_val(key, val),
			m_state(state)
		{}
	};

	vector<elem> m_table;
	size_t m_size;

	static long long s_m_primeTable[30];
	int m_primePos;
public:
	hashTable(size_t capacity = s_m_primeTable[0]) :
		m_table(capacity),
		m_size(0),
		m_primePos(0)
	{}

	size_t capacity()
	{
		return m_table.size();
	}

private:
	int hashFunc(const K & key)
	{
		SW func;
		return func(key) % capacity();
	}

	void reserve()
	{
		vector<elem> tmp;

		m_table.swap(tmp);
		m_table.resize(s_m_primeTable[++m_primePos]);

		m_size = 0;
		for (auto & e : tmp)
		{
			if (e.m_state == EXIST)
			{
				insert(e.m_val);
			}
		}
	}

public:

	bool insert(const pair<K, V> &val)
	{
		if ((long long)size() * 100 / capacity() >= 75)
		{
			reserve();
		}

		int n = hashFunc(val.first);

		while (m_table[n].m_state == EXIST)
		{
			if (m_table[n].m_val.first == val.first)
			{
				return false;
			}

			n++;
			if (n == capacity())
			{
				n = 0;
			}
		}
		m_table[n].m_val = val;
		m_table[n].m_state = EXIST;

		m_size++;
		return true;
	}

	int find(const K & key)
	{
		int n = hashFunc(key);

		while (m_table[n].m_state != EMPTY)
		{
			if (m_table[n].m_state == EXIST && m_table[n].m_val.first == key)
			{
				return n;
			}
			n++;
			if (n == capacity())
			{
				n = 0;
			}
		}
		return -1;
	}

	bool erase(const K & key)
	{
		int ret = find(key);
		if (ret < 0)
		{
			return false;
		}
		else
		{
			m_table[ret].m_state = DELETE;
			m_size--;
		}
	}

	size_t size()
	{
		return m_size;
	}

	bool empty()
	{
		return m_size == 0;
	}

	void Swap(hashTable<K, V>& ht)
	{
		m_table.swap(ht.m_table);

		size_t tmp;

		tmp = m_size;
		m_size = ht.m_size;
		ht.m_size = tmp;
	}
};

template<class K, class V, class SW>
long long hashTable<K, V, SW>::s_m_primeTable[30] = {
        11,         23,         47,         89,        179,
       353,        709,       1409,       2819,       5639,
     11273,      22531,      45061,      90121,     180233,
    360457,     720899,    1441807,    2883593,    5767169,
  11534351,   23068673,   46137359,   92274737,  184549429,
 369098771,  738197549, 1476395029, 2952790016u, 4294967291u};
};