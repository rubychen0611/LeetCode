
// @Title: 路径总和 III (Path Sum III)
// @Author: rubychen0611
// @Date: 2021-02-09 17:08:16
// @Runtime: 44 ms
// @Memory: 15 MB

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
    int pathSumStartWithRoot(TreeNode* root, int sum)
    {
        if (!root)
            return 0;
        int count = 0;
        if(sum == root -> val)
            count ++;
        count += pathSumStartWithRoot(root -> left, sum - root -> val);
        count += pathSumStartWithRoot(root -> right, sum - root -> val);
        return count;
    }
public:
    int pathSum(TreeNode* root, int sum) {
        if(!root)
            return 0;
        return pathSumStartWithRoot(root, sum) + pathSum(root -> left, sum) + pathSum(root -> right, sum);
    }
};

