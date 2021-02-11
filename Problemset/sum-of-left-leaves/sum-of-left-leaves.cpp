
// @Title: 左叶子之和 (Sum of Left Leaves)
// @Author: rubychen0611
// @Date: 2021-02-10 21:59:12
// @Runtime: 8 ms
// @Memory: 13.2 MB

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
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root)
            return 0;
        queue<TreeNode*> Q;
        Q.push(root);
        int ans = 0;
        while(!Q.empty())
        {
            TreeNode* p = Q.front();
            Q.pop();
            if(p -> left)
            {    
                if(p -> left -> left == nullptr && p -> left -> right == nullptr) 
                    ans += p -> left -> val;
                Q.push(p -> left);
            }
            if(p -> right)
                Q.push(p -> right);
        }
        return ans;
    }
};
