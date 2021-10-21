
// @Title: 往完全二叉树添加节点 (往完全二叉树添加节点)
// @Author: rubychen0611
// @Date: 2021-10-12 16:28:10
// @Runtime: 24 ms
// @Memory: 21.9 MB

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
class CBTInserter {
private:
    TreeNode* root;
    queue<TreeNode*> Q;
public:
    CBTInserter(TreeNode* root) {
        this->root = root;
        Q.push(root);
        while(!Q.empty()) {
            //cout << Q.front() << " ";
            if(Q.front()->left != nullptr) {
                Q.push(Q.front()->left);
                if(Q.front()->right != nullptr) {
                    Q.push(Q.front()->right);
                    Q.pop();
                } else
                    break;
            }
            else break;
        }
    }
    
    int insert(int val) {
        if(Q.front()->left == nullptr) {
            Q.front()->left = new TreeNode(val, nullptr, nullptr);
            Q.push(Q.front()->left);
            return Q.front()->val;
        }
        //if (Q.front()->right == nullptr) {
        Q.front()->right = new TreeNode(val, nullptr, nullptr);
        Q.push(Q.front()->right);
        int tmp = Q.front()->val;
        Q.pop();
        return tmp;
       // }
        //return -1;
    }
    
    TreeNode* get_root() {
        return this->root;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */
