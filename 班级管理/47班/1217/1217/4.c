template <class T, class Alloc = alloc>
class list 
{
 // ...
 // 实例化空间配置器
 typedef simple_alloc<list_node, Alloc> list_node_allocator;
 // ...

protected:
link_type get_node()
{
   // 调用空间配置器接口先申请节点的空间
   return list_node_allocator::allocate(); 
}

// 将节点归还给空间配置器
void put_node(link_type p) 
{
   list_node_allocator::deallocate(p);
}

// 创建节点：1. 申请空间  2. 完成节点构造
link_type create_node(const T& x)
{
   link_type p = get_node();
   construct(&p->data, x);
   return p;
}

// 销毁节点： 1. 调用析构函数清理节点中资源  2. 将节点空间归还给空间配置器
void destroy_node(link_type p)
{
	destroy(&p->data);
	put_node(p);
}

// ...
iterator insert(iterator position, const T& x)
{
	link_type tmp = create_node(x);
	tmp->next = position.node;
	tmp->prev = position.node->prev;
	(link_type(position.node->prev))->next = tmp;
	position.node->prev = tmp;
	return tmp;
}

iterator erase(iterator position) 
{
	link_type next_node = link_type(position.node->next);
	link_type prev_node = link_type(position.node->prev);
	prev_node->next = next_node;
	next_node->prev = prev_node;
	destroy_node(position.node);
	return iterator(next_node);
}

 // ...
};