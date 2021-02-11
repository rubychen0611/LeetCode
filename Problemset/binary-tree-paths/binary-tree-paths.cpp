
// @Title: 二叉树的所有路径 (Binary Tree Paths)
// @Author: rubychen0611
// @Date: 2021-02-08 15:14:46
// @Runtime: 8 ms
// @Memory: 12.3 MB

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
#include<string>
#include<vector>
using namespace std;
class Solution {
private:
    vector<string> ans;
    void addPath(vector<int> & path)
    {
        string str = "";
        int i;
        if(!path.empty())
        {
            for (i = 0; i < path.size() - 1; i++)
            {
                str += to_string(path[i]) + "->";
            }
            str += to_string(path[i]);
        }
        ans.push_back(str);
    }
    void backtracking(TreeNode* node, vector<int> & path)
    {
        path.push_back(node->val);
        if(node -> left != nullptr)
            backtracking(node->left, path);
        if(node ->right != nullptr)
            backtracking(node->right, path);
        if(node->left == nullptr && node->right == nullptr)
            addPath(path);
        path.pop_back();
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int> path;
        if(root == nullptr)
            return ans;
        backtracking(root, path);
        return ans;
    }
};

