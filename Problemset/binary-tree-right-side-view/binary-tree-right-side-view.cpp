
// @Title: 二叉树的右视图 (Binary Tree Right Side View)
// @Author: rubychen0611
// @Date: 2021-10-18 22:29:27
// @Runtime: 0 ms
// @Memory: 11.7 MB

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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if (!root) {
            return ans;
        }
        queue<TreeNode*> Q;
        Q.push(root);
        while(!Q.empty()) {
            int layerCount = Q.size();
            for(int i = 0; i < layerCount; i++) {
                TreeNode* node = Q.front();
                if (i == layerCount - 1) {
                    ans.push_back(node -> val);
                }
                if(node -> left) {
                    Q.push(node -> left);
                }
                if(node -> right) {
                    Q.push(node -> right);
                }
                Q.pop();
            }
        }
        return ans;

    }
};
