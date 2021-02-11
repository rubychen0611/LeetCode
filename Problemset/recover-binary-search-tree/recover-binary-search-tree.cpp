
// @Title: 恢复二叉搜索树 (Recover Binary Search Tree)
// @Author: rubychen0611
// @Date: 2021-02-11 16:09:05
// @Runtime: 48 ms
// @Memory: 56.7 MB

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
    vector<TreeNode*> nodes;
    void recover(TreeNode* root)
    {
        if(!root)
            return;
        recover(root -> left);
        nodes.push_back(root);
        recover(root -> right);
    }
public:
    void recoverTree(TreeNode* root) {
        recover(root);
        int n = nodes.size();
        vector<TreeNode*> swapnodes;
        int count = 0;  // 逆序对数
        TreeNode* n1,  *n2;
        for(int i = 1; i < n; i++)
        {
            if(nodes[i-1] -> val > nodes[i] -> val)
            {
                if (count == 0)
                {    
                    n1 = nodes[i-1];
                    n2 = nodes[i];
                }
                else
                    n2 = nodes[i];
                count ++;
            }
        }
    
        int tmp = n1 -> val;
        n1 -> val = n2 -> val;
        n2 -> val = tmp;
    }
};
