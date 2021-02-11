
// @Title: 从前序与中序遍历序列构造二叉树 (Construct Binary Tree from Preorder and Inorder Traversal)
// @Author: rubychen0611
// @Date: 2021-02-09 20:33:04
// @Runtime: 68 ms
// @Memory: 25.2 MB

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
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int start, int end)
    {
        TreeNode* n = new TreeNode(preorder[idx]);
        int j;
        for(j = start; j <= end; j++)
        {
            if(inorder[j] == preorder[idx])
                break;
        }
        TreeNode* left, *right;
        if(start == j)
            left = nullptr;
        else
        {
            idx ++;
            left = build(preorder, inorder, start, j - 1);
        }
        if(j == end)
            right = nullptr;
        else
        {
            idx ++;
            right = build(preorder, inorder, j + 1, end);
        }
        n -> left = left;
        n -> right = right;
        return n;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty() || inorder.empty())
            return nullptr;
        idx = 0;
        return build(preorder, inorder, 0, inorder.size() - 1);
    }
};

