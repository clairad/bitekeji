#include <stdio.h>

class a{
public:
	int a;
	
	virtual void test()
	{
		putchar('a');
	}
protected:
	int c;
};

class b : a{
	int b;
	
public:
	void test()
	{
		putchar('b');
	}
};

template <typename X>
void swapArgs(X &a, X &b)
{
	
}

void swapArgs(int &a, int &b)
{
	
}

int main()
{
	//char c = -1;
	b t;
	t.test();
//	printf("%d", sizeof(struct a));
	return 0;
} 
