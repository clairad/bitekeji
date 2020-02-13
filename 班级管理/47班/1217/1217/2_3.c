template <int inst>
void* __default_alloc_template<inst>::refill(size_t n)
{
    // 一次性向内存池索要20个n字节的小块内存
    int nobjs = 20;
    char * chunk = chunk_alloc(n, nobjs);
    
    obj ** my_free_list;
    obj *result;
    obj *current_obj, *next_obj;
    int i;

    // 如果只要了一块，直接返回给用户使用
    if (1 == nobjs) 
        return(chunk);
    
    // 找到对应的桶号
    my_free_list = free_list + FREELIST_INDEX(n);

    // 将第一块返回值用户，其他块连接在对应的桶中
    // 注：此处代码逻辑比较简单，但标准库实现稍微有点复杂，同学们可以自己实现
    result = (obj *)chunk; //返回申请出的第一片空间
    *my_free_list = next_obj = (obj *)(chunk + n); //往对应桶中挂第二片空间
    for (i = 1; ; i++)  //将剩下的空间结成链，挂在后面
    {
		current_obj = next_obj; //cur = cur->next
		next_obj = (obj *)((char *)next_obj + n); //next = next->next;
		if (nobjs - 1 == i)  //一旦是最后一块空间了
		{
			current_obj -> free_list_link = 0; //next置空跳出
			break;
		} 
		else 
		{
			current_obj -> free_list_link = next_obj;  //如果不是最后一片空间，就将他们挂成链
		}
    }
    
    return(result);
}