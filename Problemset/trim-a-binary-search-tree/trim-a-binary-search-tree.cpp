
// @Title: 修剪二叉搜索树 (Trim a Binary Search Tree)
// @Author: rubychen0611
// @Date: 2021-02-11 17:06:32
// @Runtime: 8 ms
// @Memory: 17.1 MB

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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(!root)
            return nullptr;
        if(root -> val >= low && root -> val <= high)
        {
            root -> left = trimBST(root -> left, low, high);
            root -> right = trimBST(root -> right, low, high);
        }
        else if(root -> val < low)
        {
            root -> left = nullptr;
            root = trimBST(root -> right, low, high);
        }
        else
        {
            root -> right = nullptr;
            root = trimBST(root -> left, low, high);
        }
        return root;
    }
};
