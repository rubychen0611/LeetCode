
// @Title: 二叉树中的最大路径和 (Binary Tree Maximum Path Sum)
// @Author: rubychen0611
// @Date: 2021-10-17 11:48:28
// @Runtime: 32 ms
// @Memory: 26.9 MB

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
    int max;
    int calMax(int a, int b) {
        return a > b ? a : b;
    }
    int calMax(int a, int b, int c) {
        return calMax(a, calMax (b, c));
    }
    int dfsMaxPathSum(TreeNode* root) {
        if(!root) {
            return 0;
        }
        int leftPathSum = dfsMaxPathSum(root -> left);
        int rightPathSum = dfsMaxPathSum(root -> right);
        int sum = root -> val;
        if(leftPathSum > 0) 
            sum += leftPathSum;
        if(rightPathSum > 0)
            sum += rightPathSum;
        max = calMax(max, sum);
        return calMax(root -> val, leftPathSum + root->val, rightPathSum + root->val);
    }
public:
    int maxPathSum(TreeNode* root) {
        max = root -> val;
        dfsMaxPathSum(root);
        return max;
    }
};
