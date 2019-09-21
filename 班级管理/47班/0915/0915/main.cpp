#include "String.h"
//#include <string>

int main()
{
	String s1("caixukun");
	
	/*String::iterator is;

	for (is = s1.begin(); is != s1.end(); is++)
	{
		cout << *is;
	}*/

	for (auto & i : s1)
	{
		cout << i;
	}


	/*String s1(4, 'n');
	String s2("bite");
	String s3 = s2;
	String s4("qiaobiluo");

	cout << s4.size() << endl;
	cout << s4.capacity() << endl;
	s4.resize(16, '6');
	cout << s4.size() << endl;
	cout << s4.capacity() << endl;
	
	cout << (s4 > s1) << endl;
	cout << (s4 < "666") << endl;
	cout << ("666" == s4) << endl;*/

	return 0;
}