#pragma once
#include <string.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
#define DEFAULTCAPA 16
#define COUNTCAPA(size) (((size) / DEFAULTCAPA + 1) * DEFAULTCAPA)


class String
{
	char * m_data;
	size_t m_size;
	size_t m_capacity;
public:
	String(const char * str = "") :
		m_capacity(DEFAULTCAPA)
	{
		if (nullptr == str)
		{
			str = "";
		}

		m_size = strlen(str);
		m_capacity = COUNTCAPA(m_size);
		m_data = new char[m_capacity];
		strncpy(m_data, str, m_size);
	}

	String(String &s)
	{
		m_size = s.m_size;
		m_capacity = s.m_capacity;

		m_data = new char[m_capacity];
		strcpy(m_data, s.m_data);
	}

	String & operator = (const char * str)
	{
		m_size = strlen(str);
		reserve(m_size);

		strcpy(m_data, str);
		return *this;
	}

	String & operator = (String &s)
	{
		m_size = s.m_size;
		reserve(m_size);

		strcpy(m_data, s.m_data);
		return *this;
	}

	String(size_t n, char ch):
		m_size(n),
		m_capacity(COUNTCAPA(n))
	{
		m_data = new char[m_capacity];
		memset(m_data, ch, m_size);
	}

	~String()
	{
		if (m_data)
		{
			delete[]m_data;
			m_data = NULL;
		}
		m_size = m_capacity = 0;
	}

	size_t size()
	{
		return m_size;
	}

	size_t length()
	{
		return m_size;
	}

	size_t capacity()
	{
		return m_capacity - 1;
	}

	bool empty()
	{
		return m_size == 0;
	}

	void clear()
	{
		m_size = 0;
	}

	void reserve(size_t size)
	{
		if (size >= m_capacity)
		{
			m_capacity = COUNTCAPA(size);
			m_data = (char *)realloc(m_data, m_capacity);
		}
	}

	void resize(size_t size, char ch = '\0')
	{
		reserve(size);

		if (m_size < size)
		{
			memset(m_data + m_size, ch, size - m_size);
		}
		m_size = size;
	}

	char &operator[](int i)
	{
		return m_data[i];
	}

	typedef char * iterator;

	iterator begin()
	{
		return m_data;
	}

	iterator end()
	{
		return m_data + m_size;
	}

	void push_back(char ch)
	{
		reserve(m_size);

		m_data[m_size] = ch;
		m_size++;
	}

	void pop_back(char ch)
	{
		if (!empty())
		{ 
			m_size--;
		}
	}

	String & operator += (const char * str)
	{
		int tmp = m_size;
		m_size += strlen(str);
		reserve(m_size);

		strcpy(m_data + tmp, str);
		return *this;
	}

	String & operator += (String &s)
	{
		int tmp = m_size;
		m_size += s.m_size;
		reserve(m_size);

		strcpy(m_data + tmp, s.m_data);
		return *this;
	}

	/*作业：append 两种，一种n个ch的，一种直接续字符串或容器的*/

	const char * c_str()
	{
		return m_data;
	}

	size_t find(char ch, int pos = 0)
	{
		if (pos < 0 || pos >= m_size)
		{
			return -1;
		}

		char * tmp = strchr(m_data + pos, ch);

		if (tmp)
		{
			return tmp - m_data;
		}
		return -1;
	}

	size_t find(const char *str, int pos = 0)
	{
		if (pos < 0 || pos >= m_size)
		{
			return -1;
		}

		char * tmp = strstr(m_data + pos, str);

		if (tmp)
		{
			return tmp - m_data;
		}
		return -1;
	}

	size_t find(const String &s, int pos = 0)
	{
		if (pos < 0 || pos >= m_size)
		{
			return -1;
		}

		char * tmp = strstr(m_data + pos, s.m_data);

		if (tmp)
		{
			return tmp - m_data;
		}
		return -1;
	}

	/*作业：rfind 三种*/

	String substr(size_t start, size_t num)
	{
		String tmp;

		tmp.resize(num);

		strncpy(tmp.m_data, m_data + start, num);
		return tmp;
	}

	String operator + (const char * str) const;
	String operator + (const String &s) const;
	friend String operator +(const char * str, const String &s);

	bool operator >  (const char * str) const;
	bool operator <  (const char * str) const;
	bool operator >= (const char * str) const;
	bool operator <= (const char * str) const;
	bool operator == (const char * str) const;
	bool operator != (const char * str) const;
	
	bool operator >  (const String &s) const;
	bool operator <  (const String &s) const;
	bool operator >= (const String &s) const;
	bool operator <= (const String &s) const;
	bool operator == (const String &s) const;
	bool operator != (const String &s) const;

	friend bool operator >  (const char * str, const String &s);
	friend bool operator <  (const char * str, const String &s);
	friend bool operator >= (const char * str, const String &s);
	friend bool operator <= (const char * str, const String &s);
	friend bool operator == (const char * str, const String &s);
	friend bool operator != (const char * str, const String &s);

	friend ostream & operator << (ostream & os, const String &s);
	friend istream & operator >> (istream & is, String &s);
};

ostream & operator << (ostream & os, const String &s)
{
	int i;

	for (i = 0; i < s.m_size; i++)
	{
		os << s.m_data[i];
	}

	return os;
}

istream & operator >> (istream & is, String &s)
{
	char * tmp = new char[1024];
	is.getline(tmp, 1024);

	s.m_size = strlen(tmp);
	s.m_capacity = COUNTCAPA(s.m_size);
	strcpy(s.m_data, tmp);
	delete[]tmp;

	/*delete[]s.m_data;
	s.m_data = tmp;*/
	return is;
}


String String::operator + (const char * str) const
{
	String res;

	res.m_size = m_size + strlen(str);
	res.reserve(res.m_size);

	strncpy(res.m_data, m_data, m_size);
	strcpy(res.m_data + m_size, str);

	return res;
}

String String::operator + (const String &s) const
{
	String res;

	res.m_size = m_size + s.m_size;
	res.reserve(res.m_size);

	strncpy(res.m_data, m_data, m_size);
	strncpy(res.m_data + m_size, s.m_data, s.m_size);

	return res;
}

String operator +(const char * str, const String &s)
{
	String res;

	res.m_size = strlen(str) + s.m_size;
	res.reserve(res.m_size);

	strcpy(res.m_data, str);
	strncat(res.m_data, s.m_data, s.m_size);

	return res;
}

bool String::operator >  (const char * str) const
{
	return strncmp(m_data, str, m_size) > 0;
}

bool String::operator <  (const char * str) const
{
	int tmp = strncmp(m_data, str, m_size);
	if (!tmp && strlen(str) > m_size)
	{
		return true;
	}
	return tmp < 0;
}

bool String::operator >= (const char * str) const
{
	return !(*this < str);
}

bool String::operator <= (const char * str) const
{
	return !(*this > str);
}

bool String::operator == (const char * str) const
{
	int tmp = strncmp(m_data, str, m_size);
	if (!tmp && strlen(str) == m_size)
	{
		return true;
	}
	return false;
}

bool String::operator != (const char * str) const
{
	return !(*this == str);
}

bool String::operator >  (const String &s) const
{
	int i;
	int minsize = m_size < s.m_size ? m_size : s.m_size;
	for (i = 0; i < minsize; i++)
	{
		if (m_data[i] > s.m_data[i])
		{
			return true;
		}
		else if (m_data[i] < s.m_data[i])
		{
			return false;
		}
	}
	return m_size > s.m_size;
}

bool String::operator <  (const String &s) const
{
	int i;
	int minsize = m_size < s.m_size ? m_size : s.m_size;
	for (i = 0; i < minsize; i++)
	{
		if (m_data[i] < s.m_data[i])
		{
			return true;
		}
		else if (m_data[i] > s.m_data[i])
		{
			return false;
		}
	}
	return m_size < s.m_size;
}

bool String::operator >= (const String &s) const
{
	return !(*this < s);
}

bool String::operator <= (const String &s) const
{
	return !(*this > s);
}

bool String::operator == (const String &s) const
{
	int i;
	int minsize = m_size < s.m_size ? m_size : s.m_size;
	for (i = 0; i < minsize; i++)
	{
		if (m_data[i] != s.m_data[i])
		{
			return false;
		}
	}
	return m_size == s.m_size;
}

bool String::operator != (const String &s) const
{
	return !(*this == s);
}


bool operator >  (const char * str, const String &s)
{
	int tmp = strncmp(str, s.m_data, s.m_size);
	if (!tmp && strlen(str) > s.m_size)
	{
		return true;
	}
	return tmp > 0;
}

bool operator <  (const char * str, const String &s)
{
	return strncmp(str, s.m_data, s.m_size) < 0;
}

bool operator >= (const char * str, const String &s)
{
	return !(str < s);
}

bool operator <= (const char * str, const String &s)
{
	return !(str > s);
}

bool operator == (const char * str, const String &s)
{
	int tmp = strncmp(s.m_data, str, s.m_size);
	if (!tmp && strlen(str) == s.m_size)
	{
		return true;
	}
	return false;
}
bool operator != (const char * str, const String &s)
{
	return !(str == s);
}
