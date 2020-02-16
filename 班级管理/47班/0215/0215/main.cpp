#include <iostream>
using namespace std;

#if 0
class Test
{
	int m_a;
	char m_c;
public:
	Test(int a = 0, char c = '\0'):
		m_a(a),
		m_c(c)
	{}

	Test(char c) :
		Test(0, c) //委派构造
	{}

	void show()
	{
		cout << m_a << ' ' << m_c << endl;
	}
};

int main()
{
	Test t('a');
	t.show();
	return 0;
}

#endif

#if 0

class Test
{
	int m_a;
public:
	Test() = default;
	Test(const Test &a) = delete;
	Test & operator =(const Test &a) = delete;

	Test(int a):
		m_a(a)
	{}
};

int main()
{
	Test t1;
	//Test t2 = t1;

	//t2 = t1;

	return 0;
}

#endif

#if 0
#include <cstring>
#include <vector>

class String
{
	char * m_str;
public:
	static int s_m_Ccount;
	static int s_m_Mcount;

	String(char * str = "")
	{
		if (nullptr == str)
		{
			str = "";
		}
		m_str = new char[strlen(str) + 1];
		strcpy(m_str, str);
	}

	String(const String & s) :
		m_str(new char[strlen(s.m_str) + 1])
	{
		s_m_Ccount++;
		strcpy(m_str, s.m_str);
	}

	//C++11中，移动构造函数也会默认提供，是第七个默认提供的函数。
	//默认提供的移动构造函数实现方式跟之前的拷贝构造一致，只能提供浅拷贝，不做其他操作，所以如果需要移动构造函数，最好手写。
	String(String && s) :
		m_str(s.m_str) //移动构造函数
	{
		s_m_Mcount++;
		s.m_str = nullptr;
	}

	String & operator = (const String & s)
	{
		if (this != &s)
		{
			char * ptmp = new char[strlen(s.m_str) + 1];
			strcpy(ptmp, s.m_str);
			delete []m_str;
			m_str = ptmp;
		}

		return *this;
	}

	~String()
	{
		if (m_str)
		{
			delete []m_str; 
		}
	}

	void show()
	{
		cout << m_str << endl;;
	}
};

int String::s_m_Ccount = 0;
int String::s_m_Mcount = 0;

String getString(char * str)
{
	return String(str);
}

int main()
{
	//String s("caixukun");
	//String m(move(s));
	//String test(getString("bite")); //返回值优化

	vector<String> vs;
	vs.reserve(1000);

	for (int i = 0; i < 1000; i++)
	{
		vs.push_back(String("caixukun sing jump basketball jinitaimei"));
	}

	cout << String::s_m_Ccount << endl;
	cout << String::s_m_Mcount << endl;
	return 0;
}

#endif

#if 0

int && func(int a)
{
	a += 5;

	cout << &a << endl;
	return move(a); //右值引用做返回值的时候，注意点跟引用和指针相同，也就是局部变量的引用或者指针不能直接返回。
}

int main()
{
	int a;
	int && o = 1;
	//const int & o = 1;
	int && f = func(6);

	cout << &f << endl;

	cout << f << endl;

	//o = 7;
	//cout << o;

	return 0;
}

#endif

#if 0

class Person
{
public:
	Person(char* name, char* sex, int age)
		: _name(name)
		, _sex(sex)
		, _age(age)
	{}
	Person(const Person& p)
		: _name(p._name)
		, _sex(p._sex)
		, _age(p._age)
	{}
#if 0
	Person(Person&& p)
		: _name(p._name)
		, _sex(p._sex)
		, _age(p._age)
	{}
#else
	Person(Person&& p)
		: _name(move(p._name))
		, _sex(move(p._sex))
		, _age(p._age)
	{}
#endif
private:
	String _name;
	String _sex;
	int _age;
};

Person GetTempPerson()
{
	Person p("prety", "male", 18);
	return p;
}

int main()
{
	Person p(GetTempPerson());
	return 0;
}

#endif

#if 0 //完美转发

void process(int & i)
{
	cout << "process(int &):" << i << endl;
}

void process(int && i)
{
	cout << "process(int &&):" << i << endl;
}

void mforward(int && i)
{
	cout << "mforward(int &&):" << i << endl;
	process(forward<int &&>(i));
}

void mforward(int & i)
{
	cout << "mforward(int &):" << i << endl;
	process(forward<int &>(i));
}

//通用引用
template <typename T>
void myforward(T && t)
//如果传入的是int &&，那么T就直接代表int，如果传入的是int &，那么T代表int &
//引用折叠：右值引用+右值引用=右值引用 左值引用+右值引用=左值引用
//int && && -> int &&
//int && & / int & && -> int &
{
	cout << "myforward:" << t << endl;
	process(static_cast<T &&>(t));
}

int main()
{
	int a = 6;
	process(a);
	process(2);
	process(move(a));

	mforward(a);
	mforward(2);
	mforward(move(a));
	
	myforward(a);
	myforward(2);
	myforward(move(a));
	return 0;
}

#endif

#if 0
#include <string>
#include <algorithm>

struct Goods
{
	string _name;
	double _price;
};
/*
struct Compare
{
	bool operator()(const Goods& gl, const Goods& gr)
	{
		return gl._price <= gr._price;
	}
};

int main()
{
	Goods gds[] = { { "苹果", 2.1 }, { "香蕉", 3 }, { "橙子", 2.2 }, { "菠萝", 1.5 } };
	sort(gds, gds + sizeof(gds) / sizeof(gds[0]), Compare());
	return 0;
}*/

int main()
{
	Goods gds[] = { { "苹果", 2.1 }, { "香蕉", 3 }, { "橙子", 2.2 }, { "菠萝", 1.5 } };
	sort(gds, gds + sizeof(gds) / sizeof(gds[0]), [](const Goods& gl, const Goods& gr)->bool
													{
														return gl._price <= gr._price;
													}
	);

	for (auto & e : gds)
	{
		cout << e._name << ' ' << e._price << endl;
	}
	return 0;
}

#endif

#if 0
int g;
int main()
{
	// 最简单的lambda表达式, 该lambda表达式没有任何意义
	[]{};
	// 省略参数列表和返回值类型，返回值类型由编译器推导为int
	int a = 3, b = 4;
	[a]{return a + 3; };
	// 省略了返回值类型，无返回值类型
	auto fun1 = [&](int c){g = 8; b = a + c; }; //g不是捕捉到的，而是因为g是全局变量，所以可以直接使用。
	fun1(10);
	cout << a << " " << b << endl;
	// 各部分都很完善的lambda函数
	auto fun2 = [=, &b](int c)->int{return b += a + c; };
	//auto fun2 = [&, a](int c)->int{return b += a + c; };
	cout << fun2(10) << endl;
	// 复制捕捉x
	int x = 10;
	auto add_x = [x](int a) mutable { x *= 2; return a + x; };
	cout << add_x(10) << endl;

	cout << g;
	return 0;
}

#endif

#if 0
#include <typeinfo>

void(*PF)();

class FTest
{
public:
	void operator()()
	{

	}
};

int main()
{
	auto f1 = []{cout << "hello world" << endl; };
	auto f2 = []{cout << "hello world" << endl; };
	// 此处先不解释原因，等lambda表达式底层实现原理看完后，大家就清楚了
	//f1 = f2; // 编译失败--->提示找不到operator=()
	// 允许使用一个lambda表达式拷贝构造一个新的副本
	auto f3(f2);
	f3();
	// 可以将lambda表达式赋值给相同类型的函数指针

	PF = f1;
	PF();

	cout << typeid(f1).name() << endl;
	cout << typeid(f2).name() << endl;
	cout << typeid(f3).name() << endl;
	cout << typeid(PF).name() << endl;
	return 0;
}

#endif

#include <thread>
#if 0

void func(int i, int j)
{
	cout << "I am thread." << i << ' ' << j << endl;
}

int main()
{
	thread t1(func, 2, 5);
	thread t2(func, 3, 8);

	t1.join();
	t2.join();

	cout << "I am main thread." << endl;
	return 0;
}

#endif

#if 0


int main()
{
	int a = 400;
	int b = 500;
	thread t1([&](int addnum)
				{
					a += 500;
					b += 1000;
				}, 500);
	cout << "before join, joinable=" << t1.joinable() << endl;

	t1.join();

	cout << "after join, joinable=" << t1.joinable() << endl;
	cout << a << ' ' << b << endl;
	return 0;
}
#endif

#if 1
#include <windows.h>

int main()
{
	int a = 400;
	int b = 500;
	thread t1([&](int addnum)
	{
		a += 500;
		b += 1000;

		Sleep(1000);
		cout << "I'm thread" << endl;
	}, 500);
	t1.detach();
	cout << "over" << endl;

	//Sleep(2000);

	return 0;
}
#endif