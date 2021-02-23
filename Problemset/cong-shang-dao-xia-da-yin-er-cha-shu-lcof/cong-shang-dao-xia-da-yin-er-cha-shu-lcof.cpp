
// @Title: 从上到下打印二叉树 (从上到下打印二叉树 LCOF)
// @Author: rubychen0611
// @Date: 2021-02-18 16:05:15
// @Runtime: 4 ms
// @Memory: 11.9 MB

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
    vector<int> levelOrder(TreeNode* root) {
        if(!root)
            return vector<int>();
        queue<TreeNode*> Q;
        vector<int> ans;
        Q.push(root);
        while(!Q.empty())
        {
            TreeNode* p = Q.front();
            Q.pop();
            ans.push_back(p->val);
            if(p -> left)
                Q.push(p -> left);
            if(p -> right)
                Q.push(p -> right);
        }
        return ans;
    }
};
