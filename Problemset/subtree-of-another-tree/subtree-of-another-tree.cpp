
// @Title: 另一个树的子树 (Subtree of Another Tree)
// @Author: rubychen0611
// @Date: 2021-02-10 21:52:41
// @Runtime: 28 ms
// @Memory: 28.8 MB

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
    bool isIdentical(TreeNode* s, TreeNode* t)
    {
        if(s && t)
        {
            if(s->val == t-> val)
            {
                return isIdentical(s -> left, t -> left) && isIdentical(s -> right, t -> right);
            }
            else return false;
        }
        if(!t && !s)
            return true;
        return false;
    }

public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        queue<TreeNode*> Q;
        Q.push(s);
        while(!Q.empty())
        {
            TreeNode* root = Q.front();
            Q.pop();
            if(root -> left)
                Q.push(root -> left);
            if(root -> right)
                Q.push(root -> right);
            if(isIdentical(root, t))
                return true;
        }
        return false;
    }
};
