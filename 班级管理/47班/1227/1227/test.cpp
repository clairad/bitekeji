#include <iostream>
#include "hashMap.h"
using namespace std;

int main()
{
	HashSet<int> hs;

	hs.insert(5);
	hs.insert(8);
	hs.insert(13);
	hs.insert(7);
	hs.insert(2);
	hs.insert(15);
	hs.insert(18);
	hs.insert(23);
	hs.insert(17);
	hs.insert(12);
	hs.insert(25);
	hs.insert(58);
	hs.insert(33);
	hs.insert(27);
	hs.insert(22);

	hs.erase(2);
	hs.erase(27);

	hs.clear();
	return 0;
}