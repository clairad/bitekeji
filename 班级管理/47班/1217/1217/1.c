template <int inst>  //非类型模板参数
class __malloc_alloc_template
{
private:
	static void *oom_malloc(size_t); 
public:
	// 对malloc的封装
	static void * allocate(size_t n)
	{
		// 申请空间成功，直接返回，失败交由oom_malloc处理
		void *result = malloc(n);
		if (0 == result)
			result = oom_malloc(n);
		
		return result;
	}
	// 对free的封装
	static void deallocate(void *p, size_t /* n */)
	{
		free(p);
	}
	// 模拟set_new_handle
	// 该函数的参数为函数指针，返回值类型也为函数指针
	// void (* set_malloc_handler( void (*f)() ) )()
	static void (* set_malloc_handler(void (*f)()))() //参数为void(*)()，返回值也为void(*)()
	{
		void (* old)() = __malloc_alloc_oom_handler; //保存旧有的处理函数，用于返回
		__malloc_alloc_oom_handler = f; //注册新的处理函数
		return(old);
	}
};
// malloc申请空间失败时代用该函数
template <int inst>
void * __malloc_alloc_template<inst>::oom_malloc(size_t n)
{
	void (* my_malloc_handler)();
	void *result;
	for (;;)
	{
		// 检测用户是否设置空间不足应对措施，如果没有设置，抛异常，模式new的方式
		my_malloc_handler = __malloc_alloc_oom_handler;
		if (0 == my_malloc_handler) //如果用户没有内存异常的处理函数
		{
			__THROW_BAD_ALLOC; //那么直接抛出bad alloc异常
		}
		// 如果设置，执行用户提供的空间不足应对措施
		(*my_malloc_handler)(); //一般这个函数的调用会释放一部分空间，好让下面的result能够获取到空间
		// 继续申请空间，可能就会申请成功
		result = malloc(n);
		if (result) //如果一直申请失败，则会进入死循环
			return(result);
	}
}

typedef __malloc_alloc_template<0> malloc_alloc;