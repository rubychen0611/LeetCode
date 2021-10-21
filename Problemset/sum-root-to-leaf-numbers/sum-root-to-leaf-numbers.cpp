
// @Title: 求根节点到叶节点数字之和 (Sum Root to Leaf Numbers)
// @Author: rubychen0611
// @Date: 2021-10-18 22:44:41
// @Runtime: 0 ms
// @Memory: 9 MB

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
