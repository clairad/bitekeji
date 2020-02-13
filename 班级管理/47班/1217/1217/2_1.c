template <int inst>
class __default_alloc_template 
{
private:
    enum {__ALIGN = 8};     // 如果用户所需内存不是8的整数倍，向上对齐到8的整数倍
    enum {__MAX_BYTES = 128};   // 大小内存块的分界线
    enum {__NFREELISTS = __MAX_BYTES/__ALIGN};  // 采用哈希桶保存小块内存时所需桶的个数
    
	// 如果用户所需内存块不是8的整数倍，向上对齐到8的整数倍
	static size_t ROUND_UP(size_t bytes)
	{
		return (((bytes) + __ALIGN-1) & ~(__ALIGN - 1)); //与上反7保证了低三位是0，所以得到的一定是8的倍数。
	}
  
private:
  // 用联合体来维护链表结构----同学们可以思考下此处为什么没有使用结构体
	union obj 
	{
		union obj * free_list_link; //链表指针（next）
		char client_data[1];   //指向自身的指针
	};
    
private:
    static obj *  free_list[__NFREELISTS];  //链表数组（哈希桶）
  
    // 哈希函数，根据用户提供字节数找到对应的桶号
    static  size_t FREELIST_INDEX(size_t bytes)
    {
        return (((bytes) + __ALIGN-1)/__ALIGN - 1); //除以8找到对应位置，-1可以得到下标
    }
    
    // start_free与end_free用来标记内存池中大块内存的起始与末尾位置
    static char *start_free;
    static char *end_free;
    
    // 用来记录该空间配置器已经向系统索要了多少的内存块
    static size_t heap_size;
    
    // ...
} ;



template <int inst>
class __default_alloc_template 
{
private:
    enum {__ALIGN = 8};     // 如果用户所需内存不是8的整数倍，向上对齐到8的整数倍
    enum {__MAX_BYTES = 128};   // 大小内存块的分界线
    enum {__NFREELISTS = __MAX_BYTES/__ALIGN};  // 采用哈希桶保存小块内存时所需桶的个数
    
  // 如果用户所需内存块不是8的整数倍，向上对齐到8的整数倍
  static size_t ROUND_UP(size_t bytes)
  {
        return (((bytes) + __ALIGN-1) & ~(__ALIGN - 1));
  }
  
private:
  // 用联合体来维护链表结构----同学们可以思考下此处为什么没有使用结构体
  union obj 
  {
        union obj * free_list_link;
        char client_data[1];    /* The client sees this.        */
  };
    
private:
    static obj *  free_list[__NFREELISTS]; 
  
    // 哈希函数，根据用户提供字节数找到对应的桶号
    static  size_t FREELIST_INDEX(size_t bytes)
    {
        return (((bytes) + __ALIGN-1)/__ALIGN - 1);
    }
    
    // start_free与end_free用来标记内存池中大块内存的起始与末尾位置
    static char *start_free;
    static char *end_free;
    
    // 用来记录该空间配置器已经想系统索要了多少的内存块
    static size_t heap_size;
    
    // ...
} ;