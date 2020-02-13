#include "HashBucket.h"

namespace wf{

template <class K, class V, class HF = dealInt>
class unordered_map
{
	class KeyofValue
	{
	public:
		const K& operator()(const pair<K, V> &data)
		{
			return data.first;
		}
	};

	HashBucket<K, pair<K, V>, KeyofValue, HF> m_hb;

public:
	typename typedef HashBucket<K, pair<K, V>, KeyofValue, HF>::iterator iterator;

	unordered_map():
		m_hb()
	{}

	~unordered_map()
	{
		m_hb.~HashBucket();
	}

	iterator begin()
	{
		return m_hb.begin();
	}

	iterator end()
	{
		return m_hb.end();
	}

	iterator size()
	{
		return m_hb.size();
	}

	iterator find(const V & val)
	{
		return m_hb.find(val);
	}

	size_t count(const K & key)
	{
		return m_hb.count(key); //Í¸´«
	}

	void clear()
	{
		return m_hb.clear();
	}

	bool empty()
	{
		return m_hb.empty();
	}

	pair<iterator, bool> insert(const pair<K, V> val)
	{
		return m_hb.insert(val);
	}

	V& operator[](const K & key)
	{
		pair<iterator, bool> ptmp = m_hb.insert(pair<K, V>(key, V()));
		iterator itmp = ptmp.first;
		return (*itmp).second;
	}

	const V& operator[](const K & key) const
	{
		return (*(m_hb.insert(pair<K, V>(key, V()))).first).second;
	}
};

};