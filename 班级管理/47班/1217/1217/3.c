template<class T, class Alloc>
class simple_alloc 
{
public:
	// 申请n个T类型对象大小的空间
	static T *allocate(size_t n)
	{ 
		return 0 == n? 0 : (T*) Alloc::allocate(n * sizeof (T)); 
	}
	
	// 申请一个T类型对象大小的空间
	static T *allocate(void)
	{ 
		return (T*) Alloc::allocate(sizeof (T));
	}
	
	// 释放n个T类型对象大小的空间
	static void deallocate(T *p, size_t n)
	{ 
		if (0 != n) 
			Alloc::deallocate(p, n * sizeof (T));
	}
	
	// 释放一个T类型对象大小的空间
	static void deallocate(T *p)
	{ 
		Alloc::deallocate(p, sizeof (T)); 
	}
};