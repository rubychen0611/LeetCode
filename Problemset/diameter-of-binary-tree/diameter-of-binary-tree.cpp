
// @Title: 二叉树的直径 (Diameter of Binary Tree)
// @Author: rubychen0611
// @Date: 2021-02-09 13:50:20
// @Runtime: 12 ms
// @Memory: 19.7 MB

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
    int max(int a, int b)
    {
        return a > b ? a : b;
    }
    int diameter(TreeNode* root, int & ans)
    {
        if(!root)
            return 0;
        int lh = diameter(root->left, ans), rh = diameter(root -> right,ans);
        if(lh + rh > ans)
            ans = lh + rh;
        return max(lh, rh) + 1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        int ans = 0;
        diameter(root, ans);
        return ans;
    }
};

