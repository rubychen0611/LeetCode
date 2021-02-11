
// @Title: 删点成林 (Delete Nodes And Return Forest)
// @Author: rubychen0611
// @Date: 2021-02-09 17:58:04
// @Runtime: 24 ms
// @Memory: 25.8 MB

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
private:
    vector<TreeNode*> ans;
    unordered_set<int> to_delete_set;
    bool ifDeleted(int val)
    {
        return to_delete_set.find(val) != to_delete_set.end();
    }
    void dfsDelete(TreeNode* root, TreeNode* parent)
    {
        if(!root)
            return;
        // 该节点是被删节点
        if(ifDeleted(root -> val))
        {
            dfsDelete(root -> left, nullptr);
            dfsDelete(root -> right, nullptr);
            if(parent)
            {
                if(parent -> right == root)
                    parent -> right = nullptr;
                else parent -> left = nullptr;
            }
            root -> left = nullptr;
            root -> right = nullptr;
        }
        else
        {
            dfsDelete(root -> left, root);
            dfsDelete(root -> right, root);
            if (parent == nullptr)
                ans.push_back(root);
        }

    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for(const int x: to_delete)
            to_delete_set.insert(x);
        dfsDelete(root, nullptr);
        return ans;
    }
};

