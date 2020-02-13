template <int inst>
char* __default_alloc_template<inst>::chunk_alloc(size_t size, int& nobjs)
{
    // 计算nobjs个size字节内存块的总大小以及内存池中剩余空间总大小
    char * result;
    size_t total_bytes = size * nobjs;
    size_t bytes_left = end_free - start_free;

    // 如果内存池可以提供total_bytes字节，返回
    if (bytes_left >= total_bytes) 
    {
        result = start_free;
        start_free += total_bytes;
        return(result);
    } 
    else if (bytes_left >= size)
    {
        // nobjs块无法提供，但是至少可以提供1块size字节内存块，提供后返回
        nobjs = bytes_left/size;
        total_bytes = size * nobjs;
        result = start_free;
        start_free += total_bytes;
        return(result);
    } 
    else
    {
        // 内存池空间不足，连一块小块内存都不能提供
        // 向系统堆求助，往内存池中补充空间
        // 计算向内存中补充空间大小：本次空间总大小两倍 + 向系统申请总大小/16
        size_t bytes_to_get = 2 * total_bytes + ROUND_UP(heap_size >> 4);
        
        // 如果内存池有剩余空间(该空间一定是8的整数倍)，将该空间挂到对应哈希桶中
        if (bytes_left > 0) 
        {
            // 找对应哈希桶，将剩余空间挂在其上
            obj ** my_free_list = free_list + FREELIST_INDEX(bytes_left);
            ((obj *)start_free) -> free_list_link = *my_free_list;//头插
            *my_ree_list = (obj *)start_free;
        }
        
        // 通过系统堆向内存池补充空间，如果补充成功，递归继续分配
        start_free = (char *)malloc(bytes_to_get);
        if (0 == start_free) 
        {
            // 通过系统堆补充空间失败，在哈希桶中找是否有没有使用的较大的内存块
            int i;
            obj ** my_free_list, *p;
            for (i = size; i <= __MAX_BYTES; i += __ALIGN)
            {
                my_free_list = free_list + FREELIST_INDEX(i);
                p = *my_free_list;
                
                // 如果有，将该内存块补充进内存池，递归继续分配
                if (0 != p)
                {
                    *my_free_list = p -> free_list_link; //head = head->next
                    start_free = (char *)p;
                    end_free = start_free + i;
                    return(chunk_alloc(size, nobjs));
                }
            }
            
            // 山穷水尽，只能向一级空间配置器求助
	        // 注意：此处一定要将end_free置空，因为一级空间配置器一旦抛异常就会出问题
            end_free = 0;
            start_free = (char *)malloc_alloc::allocate(bytes_to_get);
        }
        
        // 通过系统堆向内存池补充空间成功，更新信息并继续分配
        heap_size += bytes_to_get;
        end_free = start_free + bytes_to_get;
        return(chunk_alloc(size, nobjs));
    }
}