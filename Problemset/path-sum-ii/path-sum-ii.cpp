
// @Title: 路径总和 II (Path Sum II)
// @Author: rubychen0611
// @Date: 2018-07-05 16:12:44
// @Runtime: 8 ms
// @Memory: N/A

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    vector<int>* path;
    int p;
    int t;
    vector<vector<int>> vec;
public:
    void dfs(TreeNode* i)
	{
        if (i == NULL) return;
		path->push_back(i->val);
		bool le = false, re = false;
		if (i -> left == NULL)
			le = true;
		else 
			dfs(i -> left);
		if (i -> right == NULL)
			re = true;
		else
			dfs(i -> right);
		if (le && re)		//leaf
		{
			int sum = 0;
			int j;
			for (j = 0; j < path -> size(); j++)
				sum += path->at(j);
            vector<int> l;
			if (sum == t)
			{
				for (j = 0; j < path -> size(); j++)
					 l.push_back(path->at(j));
                 vec.push_back(l);
			}
		}
		path->pop_back();
	}
    vector<vector<int>> pathSum(TreeNode* root, int sum) 
    {
        path = new vector<int>;
        t = sum;
        dfs(root);
        return vec;
    }
};
