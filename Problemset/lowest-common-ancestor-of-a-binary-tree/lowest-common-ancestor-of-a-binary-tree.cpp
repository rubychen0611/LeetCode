
// @Title: 二叉树的最近公共祖先 (Lowest Common Ancestor of a Binary Tree)
// @Author: rubychen0611
// @Date: 2021-10-17 11:25:59
// @Runtime: 16 ms
// @Memory: 13.9 MB

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
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || root == p || root == q) {
            return root;
        }
        TreeNode* left = lowestCommonAncestor(root -> left, p, q);
        TreeNode* right = lowestCommonAncestor(root -> right, p, q);
        if(left == NULL) {
            return right;
        }
        if(right == NULL) {
            return left;
        }
        if(left && right) {
            return root;
        }
        return NULL;
    }
};
