
// @Title: 路径总和 (Path Sum)
// @Author: rubychen0611
// @Date: 2021-02-09 16:40:42
// @Runtime: 8 ms
// @Memory: 20.8 MB

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

public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root)
            return false;
        if (root -> left == nullptr && root -> right == nullptr)
        {
            if(targetSum == root -> val)
                return true;
            return false;
        }

        return hasPathSum(root -> left, targetSum - root -> val) || hasPathSum(root -> right, targetSum - root -> val);
    }
};

