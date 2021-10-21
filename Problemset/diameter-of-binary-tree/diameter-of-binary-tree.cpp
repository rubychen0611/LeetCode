
// @Title: 二叉树的直径 (Diameter of Binary Tree)
// @Author: rubychen0611
// @Date: 2021-10-17 16:09:18
// @Runtime: 4 ms
// @Memory: 19.9 MB

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
    int ans;
    int max(int a, int b) {
        return a > b ? a : b;
    }
    int dfsCalculateDiameter(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int leftPathCount = dfsCalculateDiameter(root -> left);
        int rightPathCount = dfsCalculateDiameter(root -> right);
        int diameter = leftPathCount + rightPathCount; 
        ans = max(ans, diameter);
        return max(leftPathCount, rightPathCount) + 1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        ans = 0;
        dfsCalculateDiameter(root);
        return ans;
    }
};
