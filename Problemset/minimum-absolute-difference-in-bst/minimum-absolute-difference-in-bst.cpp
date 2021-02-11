
// @Title: 二叉搜索树的最小绝对差 (Minimum Absolute Difference in BST)
// @Author: rubychen0611
// @Date: 2021-02-11 19:11:44
// @Runtime: 16 ms
// @Memory: 24.4 MB

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
    int last;
    int min;
    void inorder(TreeNode* root)
    {
        if(!root)
            return;
        inorder(root -> left);
        if(last != -1)
        {
            int diff = abs(last - root -> val);
            if(diff < min)
                min = diff;
        }
        last = root -> val;
        inorder(root -> right);
    }
public:
    int getMinimumDifference(TreeNode* root) {
        last = -1;
        min = INT_MAX;
        inorder(root);
        return min;
    }
};
