
// @Title: 对称二叉树 (Symmetric Tree)
// @Author: rubychen0611
// @Date: 2021-02-09 17:18:14
// @Runtime: 12 ms
// @Memory: 15.8 MB

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
    bool dfsSymmetric(TreeNode* n1, TreeNode* n2)
    {
        if(!n1 && !n2)
            return true;
        if(!n1 || !n2)
            return false;
        if(n1 -> val != n2 -> val)
            return false;
        return dfsSymmetric(n1 -> left, n2 -> right) && dfsSymmetric(n1->right, n2 -> left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        return dfsSymmetric(root -> left, root -> right);
    }
};

