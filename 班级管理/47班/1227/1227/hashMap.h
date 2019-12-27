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

public:
	HashSet(size_t capacity = 11) :
		m_data(11, nullptr),
		m_size(0)
	{}

private:
	int hashFunc(const K & key)
	{
		SW func;
		return func(key) % capacity();
	}

public:
	bool insert(const T & val)
	{
		int hashnum = hashFunc(val);
		HashBucketNode<T> * tmp;

		if (m_data[hashnum])
		{
			for (tmp = m_data[hashnum]; tmp; tmp = tmp->next)
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
			for (tmp = m_data[hashnum]; tmp->next; tmp = tmp->next)
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
};