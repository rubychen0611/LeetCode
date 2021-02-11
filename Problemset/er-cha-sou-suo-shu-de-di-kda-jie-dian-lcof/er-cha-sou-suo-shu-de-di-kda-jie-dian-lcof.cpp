
// @Title: 二叉搜索树的第k大节点 (二叉搜索树的第k大节点  LCOF)
// @Author: rubychen0611
// @Date: 2021-02-11 19:22:46
// @Runtime: 24 ms
// @Memory: 23.4 MB

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
private:
    int count;
    int ans;
    void inorder(TreeNode* root, int k)
    {
        if(!root)
            return;
        inorder(root -> right, k);
        if(count >= k)
            return;
        count ++;
        if(count == k)
        {
            ans = root -> val;
            return;
        }
        inorder(root-> left, k);
    }
public:
    int kthLargest(TreeNode* root, int k) {
        count = 0;
        ans = -1;
        inorder(root, k);
        return ans;
    }
};
