
// @Title: 二叉树的最小深度 (Minimum Depth of Binary Tree)
// @Author: rubychen0611
// @Date: 2021-02-09 13:36:21
// @Runtime: 268 ms
// @Memory: 141.1 MB

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
    int minDepth(TreeNode* root) {
        if (!root)
            return 0;
        queue<TreeNode*> Q;
        TreeNode* p;
        Q.push(root);
        int depth = 0;
        while(!Q.empty())
        {
            depth ++;
            int n = Q.size();
            for(int i = 0; i < n; i++)
            {
                p = Q.front();
                Q.pop();
                if(p->left == nullptr && p -> right == nullptr)
                    return depth;
                if(p->left)
                    Q.push(p->left);
                if(p->right)
                    Q.push(p->right);
            }
        }
        return -1;
    }
};

