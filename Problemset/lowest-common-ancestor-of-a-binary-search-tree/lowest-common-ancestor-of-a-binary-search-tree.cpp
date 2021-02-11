
// @Title: 二叉搜索树的最近公共祖先 (Lowest Common Ancestor of a Binary Search Tree)
// @Author: rubychen0611
// @Date: 2021-02-11 18:54:08
// @Runtime: 40 ms
// @Memory: 22.8 MB

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
    TreeNode* findAncestor(TreeNode* root, int low, int high)
    {
        if(!root)
            return nullptr;
        if(root -> val >= low && root -> val <= high)
            return root;
        else if(root -> val > high)
            return findAncestor(root -> left, low, high);
        else
            return findAncestor(root -> right, low, high);
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p -> val == q -> val)
            return p;
        int low = p -> val, high = q -> val;
        if(low > high)
        {
            int tmp = low;
            low = high;
            high = tmp;
        }
        return findAncestor(root, low, high);
    }
};
