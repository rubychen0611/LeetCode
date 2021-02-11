
// @Title: 验证二叉搜索树 (Validate Binary Search Tree)
// @Author: rubychen0611
// @Date: 2021-02-11 14:05:22
// @Runtime: 16 ms
// @Memory: 21.2 MB

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
    vector<int> nums;
    void inorder(TreeNode* root)
    {
        if(!root)
            return;
        inorder(root -> left);
        nums.push_back(root -> val);
        inorder(root -> right);
    }
public:
    bool isValidBST(TreeNode* root) {
        inorder(root);
        for(int i = 0; i < nums.size() - 1; i++)
        {
            if(nums[i + 1] <= nums[i])
                return false;
        }
        return true;
    }
};
