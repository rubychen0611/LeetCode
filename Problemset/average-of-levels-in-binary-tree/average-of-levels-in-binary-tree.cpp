
// @Title: 二叉树的层平均值 (Average of Levels in Binary Tree)
// @Author: rubychen0611
// @Date: 2021-02-09 18:10:27
// @Runtime: 16 ms
// @Memory: 21.9 MB

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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        queue<TreeNode*> Q;
        Q.push(root);
        while(!Q.empty())
        {
            long long sum = 0;
            int n = Q.size();
            for(int i = 0; i < n; i++)
            {
                TreeNode* p = Q.front();
                Q.pop();
                sum += p -> val;
                if(p->left)
                    Q.push(p->left);
                if(p->right)
                    Q.push(p->right);
            }
            ans.push_back((double)sum / n);
        }
        return ans;
    }
};

