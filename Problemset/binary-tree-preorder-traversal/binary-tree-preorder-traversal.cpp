
// @Title: 二叉树的前序遍历 (Binary Tree Preorder Traversal)
// @Author: rubychen0611
// @Date: 2021-02-09 20:12:27
// @Runtime: 4 ms
// @Memory: 8 MB

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
#include<vector>
using namespace std;
//class Solution {
//private:
//    vector<int> ans;
//    void preorder(TreeNode* root)
//    {
//        if(!root)
//            return;
//        ans.push_back(root->val);
//        preorder(root->left);
//        preorder(root->right);
//    }
//public:
//    vector<int> preorderTraversal(TreeNode* root) {
//        preorder(root);
//        return ans;
//    }
//};
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root)
            return ans;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty())
        {
            TreeNode* p = st.top();
            ans.push_back(p -> val);
            st.pop();
            if(p -> right)
                st.push(p -> right);
            if (p -> left)
                st.push(p -> left);
        }
        return ans;
    }
};

