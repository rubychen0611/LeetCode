
// @Title: 最大的异或 (最大的异或)
// @Author: rubychen0611
// @Date: 2021-10-20 21:09:28
// @Runtime: 232 ms
// @Memory: 63.8 MB

struct TrieNode {
    TrieNode* childNode[2];
    // 无需isVal，整数都是32位
    TrieNode () {
        for(int i = 0; i < 2; i++) {
            childNode[i] = nullptr;
        }
    }
};
class BinaryTrie {
private:
    TrieNode* root;
public:
    /** Initialize your data structure here. */
    BinaryTrie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(int num) {
        TrieNode* p = root;
        for(int i = 0; i < 32; i++) {
            int bit = (num >> (32 - i - 1)) & 1;
            //cout << bit;
            if (p -> childNode[bit] == nullptr) {
                p -> childNode[bit] = new TrieNode();
            }
            p = p -> childNode[bit];
        }
        //cout << endl;
    }
    int getMaxXor(int num1) {
        int num2 = 0;
        TrieNode* p = root;
        for(int i = 0; i < 32; i++) {
            int bit = (num1 >> (32 - i - 1)) & 1;
            if(p -> childNode[1-bit] != nullptr) { // 优先选择相反的
                p = p -> childNode[1-bit];
                num2 <<= 1;
                num2 |= (1 - bit);
            } else {
                p = p -> childNode[bit];
                num2 <<= 1;
                num2 |= bit;
            }
        }
        //cout << num1 << " " << num2 << endl;
        return num1 ^ num2;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        BinaryTrie tree;
        for (int num: nums) {
            tree.insert(num);
        }
        int max = 0;
        for (int num: nums) {
            int maxXor = tree.getMaxXor(num);
            if(maxXor > max) {
                max = maxXor;
            }
        }
        return max;
    }
};
