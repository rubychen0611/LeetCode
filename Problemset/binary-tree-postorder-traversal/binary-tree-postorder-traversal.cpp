
// @Title: 二叉树的后序遍历 (Binary Tree Postorder Traversal)
// @Author: rubychen0611
// @Date: 2021-02-09 19:57:59
// @Runtime: 0 ms
// @Memory: 8.4 MB

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
    vector<int> ans;
    void postorder(TreeNode* root)
    {
        if(!root)
            return;
        postorder(root->left);
        postorder(root->right);
        ans.push_back(root->val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        postorder(root);
        return ans;
    }
};

