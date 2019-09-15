#include<iostream>
#include<string>
using namespace std;

int __main()
{
	string s1; 
	char str[1000] = { 0 };

	//scanf("%[^\n]", str);
	//fgets(str, 1000, stdin);

	//cin.getline(str, 10);
	getline(cin, s1);

	cout << s1;

	return 0;
}



int _main()
{
	string s1("xiao zhu pai pei pai");
	string s2("pei pei");
	string s3("pei qi");

	int pos = s1.find('p');
	cout << s1.find('p', pos + 1) << endl;

	cout << s1.find(s2, 0) << endl;
	cout << s1.find(s3) << endl;
	cout << s1.find("pei pei") << endl;
	cout << s1.find("pei pei", 0, 4) << endl;

	cout << s1.rfind('i') << endl;
	
	cout << s1.substr(0, 8) << endl;

	s1.operator+=("123");
	s1 += "123";
	cout << s1;



	return 0;
}