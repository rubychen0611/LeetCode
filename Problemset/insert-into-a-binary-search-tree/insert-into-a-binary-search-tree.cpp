
// @Title: 二叉搜索树中的插入操作 (Insert into a Binary Search Tree)
// @Author: rubychen0611
// @Date: 2021-02-11 13:38:56
// @Runtime: 108 ms
// @Memory: 55.6 MB

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
    void insert(TreeNode* &root, int val)
    {
        if(root == nullptr)
        {    
            root = new TreeNode(val);
            return;
        }
        if(root -> val > val)
            return insert(root -> left, val);
        return insert(root -> right, val);
            
    }
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        insert(root, val);
        return root;
    }
};
