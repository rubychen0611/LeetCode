
// @Title: 最接近的二叉搜索树值 (Closest Binary Search Tree Value)
// @Author: rubychen0611
// @Date: 2021-02-11 14:21:56
// @Runtime: 16 ms
// @Memory: 20.5 MB

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
    double diff;
    int closest;
    void searchCloset(TreeNode* root, double target)
    {
        if(!root)
            return;
        double d = abs(root->val - target);
        if(d < diff)
        {
            diff = d;
            closest = root -> val;
        }
        if(root -> val > target)
            searchCloset(root -> left, target);
        else searchCloset(root -> right, target);
    }
public:
    int closestValue(TreeNode* root, double target) {
        diff = abs(root-> val - target);
        closest = root -> val;
        searchCloset(root, target);
        return closest;
    }
};
