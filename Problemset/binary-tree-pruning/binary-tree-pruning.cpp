
// @Title: 二叉树剪枝 (Binary Tree Pruning)
// @Author: rubychen0611
// @Date: 2021-10-18 22:37:39
// @Runtime: 4 ms
// @Memory: 8.5 MB

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
    bool pruneTreeInternal(TreeNode* root) {
        if(!root) {
            return false; // 不用剪
        }
        if (pruneTreeInternal(root -> left)) {
            root -> left = nullptr;
        }
        if (pruneTreeInternal(root -> right)) {
            root -> right = nullptr;
        }
        if(root -> left == nullptr && root -> right == nullptr
         && root ->val == 0) {
             return true;
         }
         return false;
    }
public:
    TreeNode* pruneTree(TreeNode* root) {
        if (pruneTreeInternal(root)) {
            root = nullptr;
        }
        return root;
    }
};
