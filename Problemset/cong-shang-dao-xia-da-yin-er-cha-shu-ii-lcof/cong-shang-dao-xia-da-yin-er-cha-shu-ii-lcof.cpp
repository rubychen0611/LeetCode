
// @Title: 从上到下打印二叉树 II (从上到下打印二叉树 II LCOF)
// @Author: rubychen0611
// @Date: 2021-02-18 16:07:07
// @Runtime: 8 ms
// @Memory: 12.1 MB

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)
            return ans;
        queue<TreeNode*> Q;
        Q.push(root);
        while(!Q.empty())
        {
            int size = Q.size();
            vector<int> row;
            for(int i = 0; i < size; i++)
            {
                TreeNode* p = Q.front();
                Q.pop();
                row.push_back(p->val);
                if(p -> left)
                    Q.push(p -> left);
                if(p -> right)
                    Q.push(p -> right);
            }
            ans.push_back(row);
        }
        return ans;
    }
};
