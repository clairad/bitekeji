#pragma once

#include <deque>

namespace wf
{
	template <class T, class Con = deque<T>>
	class stack
	{
		Con m_data;
	public:
		void push(const T &x)
		{
			m_data.push_back(x);
		}

		void pop()
		{
			m_data.pop_back();
		}

		int size()
		{
			return m_data.size();
		}

		T & top()
		{
			return m_data.back();
		}

		bool empty()
		{
			return m_data.empty();
		}
	};




};
