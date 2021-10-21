
// @Title: 序列化与反序列化二叉树 (序列化与反序列化二叉树)
// @Author: rubychen0611
// @Date: 2021-10-17 16:47:59
// @Runtime: 32 ms
// @Memory: 28.5 MB

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string str = "";
        queue<TreeNode*> Q;
        Q.push(root);
        TreeNode* p;
        while(!Q.empty()) {
            p = Q.front();
            Q.pop();
            if(p == NULL) {
                str += "#,";
            }
            else {
                str += to_string(p -> val) + ",";
                Q.push(p -> left);
                Q.push(p -> right);
            }
        }
        //cout << str << endl;
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<TreeNode**> Q;
        TreeNode* root = NULL;
        Q.push(&root);
        string str = "";
        for(char ch: data) {
            if(ch == ','){
                if (str.length() > 0 && !Q.empty()) 
                {
                    TreeNode** addr = Q.front();
                    Q.pop();
                    if(str == "#") {
                        *addr = NULL;
                    }
                    else {
                        int val = stoi(str);
                        TreeNode* node = new TreeNode(val);
                        *addr = node;
                        Q.push(&(node -> left));
                        Q.push(&(node -> right));
                    }
                    str = "";
                }
            }
            else {
                str += ch;
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
