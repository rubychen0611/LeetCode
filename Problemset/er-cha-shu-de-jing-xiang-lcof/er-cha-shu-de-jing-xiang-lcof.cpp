
// @Title: 二叉树的镜像 (二叉树的镜像  LCOF)
// @Author: rubychen0611
// @Date: 2021-02-18 15:56:12
// @Runtime: 0 ms
// @Memory: 8.9 MB

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
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if(!root)
            return nullptr;
        TreeNode* leftChild = mirrorTree(root -> left), *rightChild = mirrorTree(root -> right);
        root -> left = rightChild;
        root -> right = leftChild;
        return root;
    }
};
