
// @Title: 删除二叉搜索树中的节点 (Delete Node in a BST)
// @Author: rubychen0611
// @Date: 2021-02-11 14:55:22
// @Runtime: 40 ms
// @Memory: 31.9 MB

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
    void deleteBSTNode(TreeNode* &root, int key)
    {
        if(!root)
            return;
        if(root -> val > key)
            deleteBSTNode(root -> left, key);
        else if (root -> val < key)
            deleteBSTNode(root -> right, key);
        else if (root -> left && root -> right)
        {
            TreeNode* tmp = root -> right;  //寻找右子树的最左节点
            while(tmp -> left != nullptr)
                tmp = tmp -> left;
            root -> val = tmp -> val;
            deleteBSTNode(root -> right, tmp -> val);   //在右子树中删除tmp
        }
        else{
            TreeNode* tmp = root;
            if(root -> left)
                root = root -> left;
            else if(root -> right)
                root = root -> right;
            else
                root = nullptr;
            delete tmp;
        }
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)
            return nullptr;
        deleteBSTNode(root, key);
        return root;
            
    }
};
