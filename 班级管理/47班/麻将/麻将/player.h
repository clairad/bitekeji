#include <iostream>
#include <string.h>
using namespace std;

class Player
{
	char m_Hand[14];
	char m_name[20];
	int m_size;

	void insertmj(int n);
	void deletemj(int n);
public:
	Player(char *name) :
		m_size(0)
	{
		strncpy(m_name, name, 19);
	}

	void getmj(char mj);
	void showmj();
};