#pragma once

#include <vector>
#include <stack>

namespace wf{

template <class T>
class TreeNode
{
	int m_bf;
	T m_data;
	TreeNode<T> * m_left;
	TreeNode<T> * m_right;
	TreeNode<T> * m_parent;
public:
	TreeNode(const T & val = T()) :
		m_bf(0),
		m_data(val),
		m_left(nullptr),
		m_right(nullptr),
		m_parent(nullptr)
	{}

	template <class T>
	friend class AVLTree;
};

template <class T>
class AVLTree
{
	TreeNode<T> * m_root;

	void destroy(TreeNode<T> * root)
	{
		if (root)
		{
			destroy(root->m_left);
			destroy(root->m_right);
			delete root;
		}
	}

	void lRound(TreeNode<T> * pre)
	{
		TreeNode<T> * parent = pre->m_parent; //B结点
		TreeNode<T> * cur = pre->m_right;

		cur->m_parent = parent;
		if (parent)
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
			m_root = cur;
		}

		pre->m_right = cur->m_left;
		if (cur->m_left)
		{
			cur->m_left->m_parent = pre;
		}

		cur->m_left = pre;
		pre->m_parent = cur;

		cur->m_bf = pre->m_bf = 0;
	}

	void rRound(TreeNode<T> * pre)
	{
		TreeNode<T> * parent = pre->m_parent; //B结点
		TreeNode<T> * cur = pre->m_left;

		cur->m_parent = parent;
		if (parent)
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
			m_root = cur;
		}

		pre->m_left = cur->m_right;
		if (cur->m_right)
		{
			cur->m_right->m_parent = pre;
		}

		cur->m_right = pre;
		pre->m_parent = cur;

		cur->m_bf = pre->m_bf = 0;
	}

	void rlRound(TreeNode<T> * pre)
	{
		TreeNode<T> * right = pre->m_right;
		TreeNode<T> * newroot = right->m_left;

		int flag = newroot->m_bf;

		rRound(pre->m_right);
		lRound(pre);

		if (flag == -1)
		{
			right->m_bf = 1;
		}
		else if(flag == 1)
		{
			pre->m_bf = -1;
		}
	}

	void lrRound(TreeNode<T> * pre)
	{
		TreeNode<T> * left = pre->m_left;
		TreeNode<T> * newroot = left->m_right;

		int flag = newroot->m_bf;

		lRound(pre->m_left);
		rRound(pre);

		if (flag == -1)
		{
			pre->m_bf = 1;
		}
		else if(flag == 1)
		{
			left->m_bf = -1;
		}
	}
public:
	AVLTree() :
		m_root(nullptr)
	{}

	~AVLTree()
	{
		destroy(m_root);
	}

	bool insert(const T &val)
	{
		if (m_root == nullptr)
		{
			m_root = new TreeNode<T>(val);
			return true;
		}

		TreeNode<T> * cur = m_root;
		TreeNode<T> * pre = nullptr;

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

		cur = new TreeNode<T>(val);
		if (val < pre->m_data)
		{
			pre->m_left = cur;
		}
		else
		{
			pre->m_right = cur;
		}

		cur->m_parent = pre;

		while (pre)
		{
			if (pre->m_left == cur)
			{
				pre->m_bf--;
			}
			else
			{
				pre->m_bf++;
			}

			if (pre->m_bf == 0)
			{
				break;
			}
			else if (pre->m_bf == 1 || pre->m_bf == -1)
			{
				cur = pre;
				pre = pre->m_parent;
			}
			else
			{
				if (pre->m_bf == 2)
				{
					if (cur->m_bf == 1)
					{
						lRound(pre);
					}
					else
					{
						rlRound(pre);
					}
				}
				else
				{
					if (cur->m_bf == 1)
					{
						lrRound(pre);
					}
					else
					{
						rRound(pre);
					}
				}
				break;
			}
		}
		return true;
	}

	bool erase(const T &val)
	{
		if (m_root == nullptr)
		{
			return false;
		}

		TreeNode<T> * cur = m_root;
		TreeNode<T> * pre = m_root;

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
				break;
			}
		}

		if (cur == nullptr)
		{
			return false;
		}

		if (cur->m_left && cur->m_right)
		{
			TreeNode<T> * cur2 = cur->m_left;
			TreeNode<T> * pre2 = cur;

			if (cur2->m_right)
			{
				for (; cur2->m_right; pre2 = cur2, cur2 = cur2->m_right);
				pre2->m_right = cur2->m_left;
				cur2->m_left = cur->m_left;
			}

			cur2->m_right = cur->m_right;

			if (cur == pre)
			{
				m_root = cur2;
			}
			else
			{ 
				if (cur->m_data < pre->m_data)
				{
					pre->m_left = cur2;
				}
				else
				{
					pre->m_right = cur2;
				}
			}

			delete cur;
		}
		else if (cur->m_left)
		{
			if (cur == pre)
			{
				m_root = cur->m_left;
			}
			else
			{ 
				if (cur->m_data < pre->m_data)
				{
					pre->m_left = cur->m_left;
				}
				else
				{
					pre->m_right = cur->m_left;
				}
			}
			delete cur;
		}
		else
		{
			if (cur == pre)
			{
				m_root = cur->m_right;
			}
			else
			{
				if (cur->m_data < pre->m_data)
				{
					pre->m_left = cur->m_right;
				}
				else
				{
					pre->m_right = cur->m_right;
				}
			}
			
			delete cur;
		}
	}

	/*
	看是不是有左右子树：
		①左右子树都有：
			a、左子树没有右孩子
				直接让左孩子继承自己的右孩子和父亲
			b、左子树有右孩子
				一路向右，找到最后的一个右孩子，然后将这个孩子的
				左子树挂在它父亲的右子树上，然后让它继承要删除节
				点的人际关系（左右子树和父亲）
			当要删除的节点是根节点时，不用继承父亲关系，但要修改
			根节点指向。
		②只有左子树
			直接让左子树继承自己的父亲关系，如果要删的是根，那么
			直接换根即可。
		③其他
			直接让右子树（或者空）继承自己的父亲关系，其他同上
	*/

	std::vector<T> InOrder()
	{
		std::stack<TreeNode<T> *> s;
		std::vector<T> res;
		TreeNode<T> * cur = m_root;

		while (cur || !s.empty())
		{
			for (; cur; cur = cur->m_left)
			{
				s.push(cur);
			}

			if (!s.empty())
			{ 
				cur = s.top();
				res.push_back(cur->m_data);
				s.pop();

				cur = cur->m_right;
			}
		}

		return res;
	}
};



};