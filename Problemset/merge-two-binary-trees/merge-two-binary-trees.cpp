
// @Title: 合并二叉树 (Merge Two Binary Trees)
// @Author: rubychen0611
// @Date: 2021-02-10 00:36:53
// @Runtime: 44 ms
// @Memory: 31.5 MB

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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1 && root2)  // 都存在，求和
        {
            root1 -> val += root2 -> val;
        }
        else if(!root1 && root2)    // 2有1没有，复制
        {
            root1 = new TreeNode(root2->val);
        }
        else return root1;      // 1有2没有，或都没有：不动
        //继续递归复制
        root1 -> left = mergeTrees(root1 -> left, root2 -> left);   
        root1 -> right = mergeTrees(root1 -> right, root2 -> right);
        return root1;
          
    }
};
