#pragma once
#include <vector>
using namespace std;

template<class T>
class HashBucketNode
{
	T m_val;
	HashBucketNode<T> * m_next;

	HashBucketNode(const T & val = T()) :
		m_val(val),
		m_next(nullptr)
	{}

	template<class T, class SW>
	friend class HashSet;
};

class dealInt
{
public:
	int operator()(int n)
	{
		return n;
	}
};

template<class T, class SW = dealInt>
class HashSet
{
	vector<HashBucketNode<T> *> m_data;
	size_t m_size;

	static long long s_m_primeTable[30];
	int m_primePos;
public:
	HashSet(size_t capacity = s_m_primeTable[0]) :
		m_data(capacity, nullptr),
		m_size(0),
		m_primePos(0)
	{}

private:
	int hashFunc(const T & key)
	{
		SW func;
		return func(key) % capacity();
	}

	void checkCapacity()
	{
		if (m_size == capacity())
		{
			int mcapa = capacity();
			vector<HashBucketNode<T> *> tmp(s_m_primeTable[++m_primePos], nullptr);
			m_data.swap(tmp);
			m_size = 0;

			int i;
			HashBucketNode<T> * cur;
			for (i = 0; i < mcapa; i++)
			{
				for (cur = tmp[i]; cur; cur = cur->m_next)
				{
					insert(cur->m_val);
				}
			}
		}
	}

public:
	bool insert(const T & val)
	{
		checkCapacity();

		int hashnum = hashFunc(val);
		HashBucketNode<T> * tmp;

		if (m_data[hashnum])
		{
			for (tmp = m_data[hashnum]; tmp; tmp = tmp->m_next)
			{
				if (tmp->m_val == val)
				{
					return false;
				}
			}
		}

		tmp = new HashBucketNode<T>(val);

		tmp->m_next = m_data[hashnum];
		m_data[hashnum] = tmp;

		m_size++;
		return true;
	}

	bool erase(const T & val)
	{
		int hashnum = hashFunc(val);
		HashBucketNode<T> * tmp;

		if (!m_data[hashnum])
		{
			return false;
		}

		if (m_data[hashnum]->m_val == val)
		{
			tmp = m_data[hashnum];
			m_data[hashnum] = tmp->m_next;
			delete tmp;

			m_size--;
			return true;
		}
		else
		{
			for (tmp = m_data[hashnum]; tmp->m_next; tmp = tmp->m_next)
			{
				if (tmp->m_next->m_val == val)
				{
					HashBucketNode<T> * cur;
					cur = tmp->m_next;
					tmp->m_next = cur->m_next;
					delete cur;

					m_size--;
					return true;
				}
			}
			return false;
		}
	}

	size_t capacity()
	{
		return s_m_primeTable[m_primePos];
	}
};

template<class T, class SW>
long long HashSet<T, SW>::s_m_primeTable[30] = {
	11, 23, 47, 89, 179,
	353, 709, 1409, 2819, 5639,
	11273, 22531, 45061, 90121, 180233,
	360457, 720899, 1441807, 2883593, 5767169,
	11534351, 23068673, 46137359, 92274737, 184549429,
	369098771, 738197549, 1476395029, 2952790016u, 4294967291u
};
