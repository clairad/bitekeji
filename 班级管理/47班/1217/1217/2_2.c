static void * allocate(size_t n)
{
    obj * __VOLATILE * my_free_list;
    obj * __RESTRICT result;

    // 检测用户所需空间是否超过128(即是否为小块内存)
    if (n > (size_t) __MAX_BYTES) 
    {
        // 不是小块内存交由一级空间配置器处理
        return (malloc_alloc::allocate(n));
    }
    
    // 根据用户所需字节找到对应的桶号
    my_free_list = free_list + FREELIST_INDEX(n);
    result = *my_free_list;
	
	/*
	int hushnum = FREELIST_INDEX(n); 
	result = free_list[hushnum];
	*/
    
    // 如果该桶中没有内存块时，向该桶中补充空间
    if (result == 0)
    {
        // 将n向上对齐到8的整数被，保证向桶中补充内存块时，内存块一定是8的整数倍
        void *r = refill(ROUND_UP(n));
        return r;
    }
    
    // 维护桶中剩余内存块的链式关系
    *my_free_list = result -> free_list_link;
	//free_list[hushnum] = result->next;
    return (result);
};