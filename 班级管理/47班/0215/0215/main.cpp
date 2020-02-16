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
		Test(0, c) //ί�ɹ���
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

	//C++11�У��ƶ����캯��Ҳ��Ĭ���ṩ���ǵ��߸�Ĭ���ṩ�ĺ�����
	//Ĭ���ṩ���ƶ����캯��ʵ�ַ�ʽ��֮ǰ�Ŀ�������һ�£�ֻ���ṩǳ�����������������������������Ҫ�ƶ����캯���������д��
	String(String && s) :
		m_str(s.m_str) //�ƶ����캯��
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
	//String test(getString("bite")); //����ֵ�Ż�

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
	return move(a); //��ֵ����������ֵ��ʱ��ע�������ú�ָ����ͬ��Ҳ���Ǿֲ����������û���ָ�벻��ֱ�ӷ��ء�
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

#if 0 //����ת��

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

//ͨ������
template <typename T>
void myforward(T && t)
//����������int &&����ôT��ֱ�Ӵ���int������������int &����ôT����int &
//�����۵�����ֵ����+��ֵ����=��ֵ���� ��ֵ����+��ֵ����=��ֵ����
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
	Goods gds[] = { { "ƻ��", 2.1 }, { "�㽶", 3 }, { "����", 2.2 }, { "����", 1.5 } };
	sort(gds, gds + sizeof(gds) / sizeof(gds[0]), Compare());
	return 0;
}*/

int main()
{
	Goods gds[] = { { "ƻ��", 2.1 }, { "�㽶", 3 }, { "����", 2.2 }, { "����", 1.5 } };
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
	// ��򵥵�lambda���ʽ, ��lambda���ʽû���κ�����
	[]{};
	// ʡ�Բ����б�ͷ���ֵ���ͣ�����ֵ�����ɱ������Ƶ�Ϊint
	int a = 3, b = 4;
	[a]{return a + 3; };
	// ʡ���˷���ֵ���ͣ��޷���ֵ����
	auto fun1 = [&](int c){g = 8; b = a + c; }; //g���ǲ�׽���ģ�������Ϊg��ȫ�ֱ��������Կ���ֱ��ʹ�á�
	fun1(10);
	cout << a << " " << b << endl;
	// �����ֶ������Ƶ�lambda����
	auto fun2 = [=, &b](int c)->int{return b += a + c; };
	//auto fun2 = [&, a](int c)->int{return b += a + c; };
	cout << fun2(10) << endl;
	// ���Ʋ�׽x
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
	// �˴��Ȳ�����ԭ�򣬵�lambda���ʽ�ײ�ʵ��ԭ����󣬴�Ҿ������
	//f1 = f2; // ����ʧ��--->��ʾ�Ҳ���operator=()
	// ����ʹ��һ��lambda���ʽ��������һ���µĸ���
	auto f3(f2);
	f3();
	// ���Խ�lambda���ʽ��ֵ����ͬ���͵ĺ���ָ��

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