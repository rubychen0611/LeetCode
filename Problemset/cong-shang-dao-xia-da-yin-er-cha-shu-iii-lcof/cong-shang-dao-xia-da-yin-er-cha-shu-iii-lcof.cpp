
// @Title: 从上到下打印二叉树 III (从上到下打印二叉树 III LCOF)
// @Author: rubychen0611
// @Date: 2021-02-18 16:12:38
// @Runtime: 4 ms
// @Memory: 12.6 MB

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
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)
            return ans;
        deque<TreeNode*> Q;
        Q.push_front(root);
        bool flag = false;
        while(!Q.empty())
        {
            int size = Q.size();
            vector<int> row;
            for(int i = 0; i < size; i++)
            {
                if(!flag)
                {
                    TreeNode* p = Q.front();
                    Q.pop_front();
                    row.push_back(p->val);
                    if(p -> left)
                        Q.push_back(p -> left);
                    if(p -> right)
                        Q.push_back(p -> right);
                }
                else
                {
                    TreeNode* p = Q.back();
                    Q.pop_back();
                    row.push_back(p->val);
                    if(p -> right)
                        Q.push_front(p -> right);
                    if(p -> left)
                        Q.push_front(p -> left);
                }
            }
            ans.push_back(row);
            flag = !flag;
        }
        return ans;
    }
};
