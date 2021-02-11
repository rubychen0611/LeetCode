
// @Title: 二叉搜索树中的搜索 (Search in a Binary Search Tree)
// @Author: rubychen0611
// @Date: 2021-02-11 13:32:33
// @Runtime: 44 ms
// @Memory: 34 MB

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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root)
            return nullptr;
        if(root -> val == val)
            return root;
        if(root -> val > val)
            return searchBST(root -> left, val);
        return searchBST(root -> right, val);
    }
};
