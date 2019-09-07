#include <iostream>
#include <stdlib.h>
using namespace std;

template <class T>
class SeqList{
	T * m_data;
	size_t m_size;
	size_t m_capacity;

	void checkCapacity();
public:
	SeqList(size_t capacity = 10) :
		m_data(new T[capacity]),
		m_size(0),
		m_capacity(capacity)
	{
	}

	void push_back(const T &src);
	void pop_back();

	int size();

	~SeqList();
};



template <class T>
void SeqList<T>::checkCapacity()
{
	if (m_size == m_capacity)
	{
		m_capacity *= 2;

		m_data = (T *)realloc(m_data, sizeof(T) * m_capacity);
		/*T * newSpace = new T[m_capacity];
		for (int i = 0; i < m_size; i++)
		{
		newSpace[i] = m_data[i];
		}
		delete[] m_data;
		m_data = newSpace;*/
	}
}

template <class T>
void SeqList<T>::push_back(const T &src)
{
	checkCapacity();

	m_data[m_size] = src;
	m_size++;
}

template <class T>
void SeqList<T>::pop_back()
{
	if (m_size == 0)
	{
		return;
	}
	m_size--;
}

template <class T>
int SeqList<T>::size()
{
	return m_size;
}

template <class T>
SeqList<T>::~SeqList()
{
	if (m_data)
	{
		delete[] m_data;
	}
	m_size = m_capacity = 0;
}

int main()
{
	SeqList<int> sl;

	sl.push_back(6);
	sl.push_back(7);
	sl.pop_back();

	cout << sl.size() << endl;
	return 0;
}
