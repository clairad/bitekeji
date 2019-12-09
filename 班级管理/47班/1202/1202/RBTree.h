#pragma once

namespace wf{

enum Color {RED, BLACK};

template <class T>
class RBTreeNode
{
	T m_data;
	RBTreeNode<T> * m_left;
	RBTreeNode<T> * m_right;
	RBTreeNode<T> * m_parent;
	Color m_color;

public:
	RBTreeNode(const T & val = T(), Color color = RED):
		m_left(nullptr),
		m_right(nullptr),
		m_parent(nullptr),
		m_data(val),
		m_color(color)
	{}

	template <class T>
	friend class RBTree;
};

template <class T>
class RBTree
{
	RBTreeNode<T> * m_head;

	void lRound(RBTreeNode<T> * pre)
	{
		RBTreeNode<T> * parent = pre->m_parent;
		RBTreeNode<T> * cur = pre->m_right;

		cur->m_parent = parent;
		if (parent != m_head)
		{
			if (parent->m_left == pre)
			{
				parent->m_left = cur;
			}
			else
			{
				parent->m_right = cur;
			}
		}
		else
		{
			m_head->m_parent = cur;
			cur->m_parent = m_head;
		}

		pre->m_right = cur->m_left;
		if (cur->m_left)
		{
			cur->m_left->m_parent = pre;
		}

		cur->m_left = pre;
		pre->m_parent = cur;
	}

	void rRound(RBTreeNode<T> * pre)
	{
		RBTreeNode<T> * parent = pre->m_parent;
		RBTreeNode<T> * cur = pre->m_left;

		cur->m_parent = parent;
		if (parent != m_head)
		{
			if (parent->m_left == pre)
			{
				parent->m_left = cur;
			}
			else
			{
				parent->m_right = cur;
			}
		}
		else
		{
			m_head->m_parent = cur;
			cur->m_parent = m_head;
		}

		pre->m_left = cur->m_right;
		if (cur->m_right)
		{
			cur->m_right->m_parent = pre;
		}

		cur->m_right = pre;
		pre->m_parent = cur;
	}
public:
	RBTree()
	{
		m_head = new RBTreeNode < T > ;
	}

	RBTreeNode<T> * & getRoot()
	{
		return m_head->m_parent;
	}

	RBTreeNode<T> * leftMost()
	{
		RBTreeNode<T> * cur = getRoot();

		for (; cur->m_left; cur = cur->m_left);
		return cur;
	}

	RBTreeNode<T> * rightMost()
	{
		RBTreeNode<T> * cur = getRoot();

		for (; cur->m_right; cur = cur->m_right);
		return cur;
	}

	bool insert(const T & val)
	{
		RBTreeNode<T> * & root = getRoot();

		if (root)
		{
			RBTreeNode<T> * cur = root;
			RBTreeNode<T> * pre = nullptr;

			while (cur)
			{
				if (val < cur->m_data)
				{
					pre = cur;
					cur = cur->m_left;
				}
				else if (val > cur->m_data)
				{
					pre = cur;
					cur = cur->m_right;
				}
				else
				{
					return false;
				}
			}

			cur = new RBTreeNode<T>(val);
			if (val < pre->m_data)
			{
				pre->m_left = cur;
			}
			else
			{
				pre->m_right = cur;
			}

			cur->m_parent = pre;

			/*****************红黑树*****************/

			if (pre->m_color == RED)
			{
				RBTreeNode<T> * grand = pre->m_parent;
				RBTreeNode<T> * uncle;

				if (pre == grand->m_left)
				{
					while (pre != m_head && pre->m_color == RED)
					{
						grand = pre->m_parent;
						uncle = grand->m_right;

						if (uncle && uncle->m_color == RED) //第三种情况
						{
							pre->m_color = BLACK;
							uncle->m_color = BLACK;
							grand->m_color = RED;

							cur = grand;
							pre = cur->m_parent;
						}
						else
						{
							if (cur == pre->m_right) //第五种情况转成第四种
							{
								lRound(pre);
								RBTreeNode<T> * tmp;
								tmp = pre;
								pre = cur;
								cur = tmp;
							}

							rRound(grand);        //第四种情况
							pre->m_color = BLACK;
							grand->m_color = RED;
							break;
						}
					}
				}
				else /*************上下是镜像**************/
				{
					while (pre != m_head && pre->m_color == RED)
					{
						grand = pre->m_parent;
						uncle = grand->m_left;

						if (uncle && uncle->m_color == RED)
						{
							pre->m_color = BLACK;
							uncle->m_color = BLACK;
							grand->m_color = RED;

							cur = grand;
							pre = cur->m_parent;
						}
						else
						{
							if (cur == pre->m_left)
							{
								rRound(pre);
								RBTreeNode<T> * tmp;
								tmp = pre;
								pre = cur;
								cur = tmp;
							}

							lRound(grand);
							pre->m_color = BLACK;
							grand->m_color = RED;
							break;
						}
					}
				}
			}
			//省略的else是第二种情况
		}
		else //第一种情况
		{
			root = new RBTreeNode<T>(val, BLACK);
			root->m_parent = m_head;
			m_head->m_parent = root;
		}

		root->m_color = BLACK;
		m_head->m_left = leftMost();
		m_head->m_right = rightMost();
		return true;
	}
};

};