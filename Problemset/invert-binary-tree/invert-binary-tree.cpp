
// @Title: 翻转二叉树 (Invert Binary Tree)
// @Author: rubychen0611
// @Date: 2021-02-10 00:17:31
// @Runtime: 0 ms
// @Memory: 8.9 MB

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
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root)
            return root;
        TreeNode* tmp = root -> left;
        root -> left = root -> right;
        root -> right = tmp;
        invertTree(root -> left);
        invertTree(root -> right);
        return root;
    }
};
