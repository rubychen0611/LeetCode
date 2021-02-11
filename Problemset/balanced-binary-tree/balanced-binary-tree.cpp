
// @Title: 平衡二叉树 (Balanced Binary Tree)
// @Author: rubychen0611
// @Date: 2021-02-09 13:27:50
// @Runtime: 20 ms
// @Memory: 20.5 MB

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
    int max (int a, int b)
    {
        return a > b ? a : b;
    }
    int maxDepth(TreeNode* root) {
        if (!root)
            return 0;
        int left = maxDepth(root -> left);
        int right = maxDepth(root -> right);
        return max(left, right) + 1;
    }
public:
    bool isBalanced(TreeNode* root) {
        if (!root)
            return true;
        if(root->left && !isBalanced(root->left))
            return false;
        if(root->right&& !isBalanced(root->right))
            return false;
        int lh = maxDepth(root -> left), rh = maxDepth(root->right);
        if(abs(lh-rh) <= 1)
            return true;
        return false;
    }
};

