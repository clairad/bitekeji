#include <stdio.h>
#include "mj.h"
#include "player.h"

int main()
{
	MJMontain m;
	Player p[4] = { "wang", "zhang", "li", "zhao" };

	m.createMontain();
	m.shootCrap();

	//m.outputMontain();

	//cout << m;

	for (int i = 0; i < 13; i++)
	{
		p[0].getmj(m.sendmj());
		//p[0].showmj();
	}

	while (1)
	{
		p[0].getmj(m.sendmj());
	}
	return 0;
}