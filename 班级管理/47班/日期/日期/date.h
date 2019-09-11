#pragma once
#include <iostream>
using namespace std;
typedef unsigned int uint;

class Date{
	int m_year;
	uint m_month;
	uint m_day;

	uint getDayOfYear();
public:
	Date(int y, uint m, uint d) :
		m_year(y),
		m_month(m),
		m_day(d)
	{

	}

	~Date()
	{
		//cout << "123" << endl;
	}

	Date operator + (uint delay) const;
	Date operator - (uint delay) const;
	int operator - (const Date & d) const;

	bool operator <(const Date & d) const;
	bool operator >(const Date & d) const;
	bool operator <=(const Date & d) const;
	bool operator >=(const Date & d) const;
	bool operator ==(const Date & d) const;
	bool operator !=(const Date & d) const;

	Date operator ++();
	Date operator ++(int);
	Date operator --();
	Date operator --(int);

	friend ostream &operator << (ostream & os, Date & d);
};