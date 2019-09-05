#pragma once
#include <iostream>
using namespace std;

#define MJNUM 136

class MJMontain
{
	unsigned char m_allmj[MJNUM];
	int m_getFlag;

	void fillRandNum();
public:
	MJMontain();

	void createMontain();
	void outputMontain();

	void shootCrap();

	char sendmj();

	friend ostream & operator << (ostream & os, MJMontain & data);
};