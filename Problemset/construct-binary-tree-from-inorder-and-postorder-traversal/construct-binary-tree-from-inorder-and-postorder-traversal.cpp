
// @Title: 从中序与后序遍历序列构造二叉树 (Construct Binary Tree from Inorder and Postorder Traversal)
// @Author: rubychen0611
// @Date: 2021-02-09 20:43:17
// @Runtime: 28 ms
// @Memory: 25.1 MB

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
    int idx;
    TreeNode* build(vector<int>& postorder, vector<int>& inorder, int start, int end)
    {
        TreeNode* n = new TreeNode(postorder[idx]);
        int j;
        for(j = start; j <= end; j++)
        {
            if(inorder[j] == postorder[idx])
                break;
        }
        TreeNode* left, *right;
        if(j == end)
            right = nullptr;
        else
        {
            idx --;
            right = build(postorder, inorder, j + 1, end);
        }
        if(start == j)
            left = nullptr;
        else
        {
            idx --;
            left = build(postorder, inorder, start, j - 1);
        }
        n -> left = left;
        n -> right = right;
        return n;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(postorder.empty() || inorder.empty())
            return nullptr;
        idx = postorder.size() - 1;
        return build(postorder, inorder, 0, inorder.size() - 1);
    }
};

