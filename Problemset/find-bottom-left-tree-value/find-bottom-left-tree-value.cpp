
// @Title: 找树左下角的值 (Find Bottom Left Tree Value)
// @Author: rubychen0611
// @Date: 2021-02-10 22:04:29
// @Runtime: 20 ms
// @Memory: 21.1 MB

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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> Q;
        Q.push(root);
        int left;
        while(!Q.empty())
        {
            int n = Q.size();
            for(int i = 0; i < n; i++)
            {
                TreeNode* p = Q.front();
                Q.pop();
                if(i == 0)
                    left = p -> val;
                if(p -> left)
                    Q.push(p -> left);
                if(p -> right)
                    Q.push(p -> right);
            }
        }
        return left;
    }
};
