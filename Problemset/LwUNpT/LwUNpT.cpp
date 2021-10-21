
// @Title: 二叉树最底层最左边的值 (二叉树最底层最左边的值)
// @Author: rubychen0611
// @Date: 2021-10-18 22:24:37
// @Runtime: 16 ms
// @Memory: 21.3 MB

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
        int bottomLeftValue = root -> val;
        int layerCount = 1;
        while(!Q.empty()) {
            bottomLeftValue = Q.front()->val;
            int nextLayerCount = 0;
            for(int i = 0; i < layerCount; i++) {
                TreeNode* node = Q.front();
                if(node -> left) {
                    Q.push(node -> left);
                    nextLayerCount ++;
                }
                if(node -> right) {
                    Q.push(node -> right);
                    nextLayerCount ++;
                }
                Q.pop();
            }
            layerCount = nextLayerCount;
        }
        return bottomLeftValue;
    }
};
