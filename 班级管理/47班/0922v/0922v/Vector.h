#pragma once

namespace wf
{

template <class T>
class vector
{
	T * m_start;
	T * m_finish;
	T * m_endOfStorage;
public:
	typedef T * iterator;
	typedef const T * const_iterator;
	
	vector() :
		m_start(nullptr),
		m_finish(nullptr),
		m_endOfStorage(nullptr)
	{

	}
	
	vector(int n, const T &val = T()) :
		m_start(nullptr),
		m_finish(nullptr),
		m_endOfStorage(nullptr)
	{
		reserve(n);

		for (int i = 0; i < n; i++)
		{
			m_start[i] = val;
		}
		m_finish = m_start + n;
	}

	vector(T * start, T * end) :
		m_start(nullptr),
		m_finish(nullptr),
		m_endOfStorage(nullptr)
	{
		int _size = end - start;
		reserve(_size);

		for (int i = 0; i < _size; i++)
		{
			m_start[i] = start[i];
		}
		m_finish = m_start + _size;
	}

	iterator begin()
	{
		return m_start;
	}

	iterator end()
	{
		return m_finish;
	}

	size_t size()
	{
		return m_finish - m_start;
	}

	size_t capacity()
	{
		return m_endOfStorage - m_start;
	}

	T & operator [] (int i)
	{
		return m_start[i];
	}

	void reserve(size_t _size)
	{
		int _capacity = capacity();

		if (_capacity < _size)
		{
			if (_capacity == 0)
			{
				_capacity = 1;
			}

			while(_capacity < _size)
			{
				_capacity *= 2;
			}
		}

		T * tmp = new T[_capacity];
		m_endOfStorage = tmp + _capacity;
		m_finish = tmp + size();
		if (m_start != nullptr)
		{
			for (int i = 0; i < size(); i++)
			{
				tmp[i] = m_start[i];
			}
			delete[] m_start;
		}
		m_start = tmp;
	}
};
};