#pragma once

namespace wf{

template<class T>
class ListNode{
public:
	T m_val;
	ListNode * m_prev;
	ListNode * m_next;

	ListNode(const T &val = T()):
		m_prev(nullptr),
		m_next(nullptr),
		m_val(val)
	{
	}
};

//size empty swap front back operator=
template<class T>
class list
{
	ListNode<T> * m_head;

	void createHead()
	{
		m_head = new ListNode<T>;
		m_head->m_next = m_head->m_prev = m_head;
	}

public:
	class iterator
	{
	public:
		ListNode<T> * m_pos;

		iterator(ListNode<T> * val = nullptr):
			m_pos(val)
		{

		}

		T & operator*() const
		{
			return m_pos->m_val;
		}

		T * operator->() const
		{
			return &m_pos->m_val;
		}

		iterator operator++()
		{
			m_pos = m_pos->m_next;
			return *this;
		}

		iterator operator++(int)
		{
			iterator tmp = *this;
			m_pos = m_pos->m_next;
			return tmp;
		}

		iterator operator--()
		{
			m_pos = m_pos->m_prev;
			return *this;
		}

		iterator operator--(int)
		{
			iterator tmp = *this;
			m_pos = m_pos->m_prev;
			return tmp;
		}

		bool operator==(const iterator & ci) const
		{
			return m_pos == ci.m_pos;
		}

		bool operator!=(const iterator & ci) const
		{
			return m_pos != ci.m_pos;
		}
	};

	list()
	{
		createHead();
	}

	list(int n, const T &val = T())
	{
		createHead();

		int i;
		for (i = 0; i < n; i++)
		{
			push_back(val);
		}
	}

	list(iterator start, iterator finish)
	{
		createHead();

		insert(end(), start, finish);
	}

	list(T * start, T * finish)
	{
		createHead();

		insert(end(), start, finish);
	}

	list(list<T> & l)
	{
		createHead();

		insert(end(), l.begin(), l.end());
	}
	
	~list()
	{
		erase(begin(), end());
		delete m_head;
	}

	void clear()
	{
		erase(begin(), end());
	}

	void push_back(const T &val)
	{
		insert(end(), val);
	}

	void push_front(const T &val)
	{
		insert(begin(), val);
	}

	void pop_back()
	{
		erase(--end());
	}

	void pop_front()
	{
		erase(begin());
	}

	iterator insert(iterator pos, const T &val)
	{
		ListNode<T> * cur = new ListNode < T > ;
		ListNode<T> * npos = pos.m_pos;

		cur->m_val = val;

		cur->m_prev = npos->m_prev;
		cur->m_prev->m_next = cur;

		cur->m_next = npos;
		npos->m_prev = cur;

		return cur;
	}

	iterator insert(iterator pos, T * start, T * finish)
	{
		T * tmp;
		iterator tmpit = --pos;
		pos++;

		for (tmp = start; tmp != finish; tmp++)
		{
			insert(pos, *tmp);
		}

		return ++tmpit;
	}

	iterator insert(iterator pos, iterator start, iterator end)
	{
		iterator tmp;
		iterator tmpit = --pos;
		pos++;

		for (tmp = start; tmp != end; tmp++)
		{
			insert(pos, *tmp);
		}

		return ++tmpit;
	}

	iterator erase(iterator pos)
	{
		ListNode<T> * npos = pos.m_pos;
		ListNode<T> * res = npos->m_next;

		npos->m_next->m_prev = npos->m_prev;
		npos->m_prev->m_next = npos->m_next;
		delete npos;

		return res;
	}

	iterator erase(iterator start, iterator finish)
	{
		iterator i;

		for (i = start; i != finish; i++)
		{
			erase(i);
		}

		return finish;
	}

	iterator begin()
	{
		return m_head->m_next;
	}

	iterator end()
	{
		return m_head;
	}
};

};