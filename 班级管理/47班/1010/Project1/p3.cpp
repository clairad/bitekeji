#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> levelOrder(TreeNode* root)
{
	vector<vector<int>> res;
	if (!root)
	{
		return res;
	}
	vector<int> vtmp;
	queue<TreeNode *> qu;
	TreeNode * cur;
	int len = 1;
	

	qu.push(root);

	while (!qu.empty())
	{
		for (int i = 0; i < len; i++)
		{ 
			cur = qu.front();
			vtmp.push_back(cur->val);
			qu.pop();

			if (cur->left)
			{
				qu.push(cur->left);
			}

			if (cur->right)
			{
				qu.push(cur->right);
			}
		}
		res.push_back(vtmp);
		vtmp.clear();
		len = qu.size();
	}

	return res;
}

int p3()
{
	TreeNode * root = new TreeNode(3);

	TreeNode * tmpl = new TreeNode(9);
	root->left = tmpl;
	TreeNode * tmpr = new TreeNode(20);
	root->right = tmpr;

	TreeNode * tmpll = new TreeNode(11);
	tmpl->left = tmpll;
	TreeNode * tmplr = new TreeNode(8);
	tmpl->right = tmplr;

	TreeNode * tmprl = new TreeNode(15);
	tmpr->left = tmprl;
	TreeNode * tmprr = new TreeNode(7);
	tmpr->right = tmprr;

	TreeNode * tmprrr = new TreeNode(2);
	tmprr->right = tmprrr;

	levelOrder(root);
	return 0;
}