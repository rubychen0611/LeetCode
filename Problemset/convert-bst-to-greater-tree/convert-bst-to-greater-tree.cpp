
// @Title: 把二叉搜索树转换为累加树 (Convert BST to Greater Tree)
// @Author: rubychen0611
// @Date: 2021-02-11 17:42:05
// @Runtime: 44 ms
// @Memory: 32.6 MB

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
    int cur_sum; 
    void convert(TreeNode* root)
    {
        if(!root)
            return;
        
        convert(root -> right);
        cur_sum += root -> val;
        root -> val = cur_sum;
        convert(root -> left);
    }
public:
    TreeNode* convertBST(TreeNode* root) {
        cur_sum = 0;
        convert(root);
        return root;
    }
};
