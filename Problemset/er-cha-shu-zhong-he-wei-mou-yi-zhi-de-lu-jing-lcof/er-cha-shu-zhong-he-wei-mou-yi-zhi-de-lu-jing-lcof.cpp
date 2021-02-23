
// @Title: 二叉树中和为某一值的路径 (二叉树中和为某一值的路径 LCOF)
// @Author: rubychen0611
// @Date: 2021-02-18 20:31:09
// @Runtime: 16 ms
// @Memory: 19.4 MB

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
    vector<vector<int>> ans;
    void dfs(TreeNode* root, vector<int>& path, int sum)    
    {
        if(!root)
            return;
        path.push_back(root -> val);
        if(root -> left == nullptr && root -> right == nullptr)
        {
            if(sum == root -> val)
                ans.push_back(path);
            path.pop_back();
            return;
        }
        dfs(root -> left, path, sum - root -> val);
        dfs(root -> right, path, sum - root -> val);
        path.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> path;
        dfs(root, path, sum);
        return ans;
    }
};
