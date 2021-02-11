
// @Title: 路径总和 II (Path Sum II)
// @Author: rubychen0611
// @Date: 2021-02-09 16:50:12
// @Runtime: 4 ms
// @Memory: 19.3 MB

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    vector<vector<int>> ans;
    void backtracking(TreeNode* root, vector<int> & path, int targetSum)
    {
        if (!root)
            return;
        path.push_back(root -> val);
        // 是叶结点
        if(root -> left == nullptr && root -> right == nullptr)
        {
            if(targetSum == root -> val)
                ans.push_back(path);
        }
        else
        {
            // 非叶节点
            backtracking(root->left, path, targetSum - root->val);
            backtracking(root->right, path, targetSum - root->val);
        }
        path.pop_back();
        return;

    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        backtracking(root, path, targetSum);
        return ans;
    }
};

