
// @Title: 递增顺序查找树 (Increasing Order Search Tree)
// @Author: rubychen0611
// @Date: 2021-02-12 14:47:42
// @Runtime: 0 ms
// @Memory: 7.4 MB

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
    TreeNode* new_root;
    TreeNode* successor;
    void inorder(TreeNode* root)
    {
        if(!root)
            return;
        inorder(root -> left);
        if(!new_root)
        {   
            new_root = root;
            successor = root;
        }
        else
        {
            successor -> right = root;
            successor = root;
            
        }
        root -> left = nullptr;
        inorder(root -> right);
    }
public:
    TreeNode* increasingBST(TreeNode* root) {
        new_root = nullptr;
        successor = nullptr;
        inorder(root);
        return new_root;
    }
};
