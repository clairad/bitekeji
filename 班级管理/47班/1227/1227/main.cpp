#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

bool judgePrime(long long n)
{
	int sn = (int)sqrt(n);
	int i;
	for (i = 2; i <= sn; i++)
	{
		if (n % i == 0)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	unsigned long long start = 26;

	unsigned long long i, j;
	int count = 0;
	for (i = start; i < 3E9; i *= 2)
	{
		for (j = i; !judgePrime(j); j++);
		count++;
		if (count % 5 == 0)
		{
			cout << endl;
		}
		printf("%10lld, ", j);
	}

	for (i = 0xffffffff; !judgePrime(i); i--);
	cout << i;
	return 0;
}