
// @Title: 从根节点到叶节点的路径数字之和 (从根节点到叶节点的路径数字之和)
// @Author: rubychen0611
// @Date: 2021-10-18 22:44:21
// @Runtime: 4 ms
// @Memory: 8.9 MB

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
    int sum;
    void sumNumbersInternal(TreeNode* root, int last) {
        if(!root) {
            return;
        }
        int next = last * 10 + root -> val;
        if(root -> left == nullptr && root -> right == nullptr) {
            sum += next;
            return;
        }
        sumNumbersInternal(root -> left, next);
        sumNumbersInternal(root -> right, next);
    }
public:
    int sumNumbers(TreeNode* root) {
        sum = 0;
        sumNumbersInternal(root, 0);
        return sum;
    }
};
