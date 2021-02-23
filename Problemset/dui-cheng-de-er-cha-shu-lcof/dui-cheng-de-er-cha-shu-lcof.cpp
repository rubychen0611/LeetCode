
// @Title: 对称的二叉树 (对称的二叉树  LCOF)
// @Author: rubychen0611
// @Date: 2021-02-18 16:00:49
// @Runtime: 4 ms
// @Memory: 15.9 MB

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
private:
    bool ifSymmetric(TreeNode* r1, TreeNode * r2)
    {
        if(!r1 && !r2)
            return true;
        if(!r1 || !r2)
            return false;
        if(r1 -> val != r2 -> val)
            return false;
        return ifSymmetric(r1 -> left, r2 -> right) && ifSymmetric(r1 -> right, r2 -> left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        return ifSymmetric(root -> left, root -> right);  
    }
};
