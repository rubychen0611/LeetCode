
// @Title: 最短的单词编码 (最短的单词编码)
// @Author: rubychen0611
// @Date: 2021-10-20 20:22:34
// @Runtime: 48 ms
// @Memory: 72.2 MB

struct TrieNode {
    TrieNode* childNode[26];
    bool isVal;
    TrieNode () {
        isVal = false;
        for(int i = 0; i < 26; i++) {
            childNode[i] = nullptr;
        }
    }
};
// 后缀树！
class Trie {
private:
    TrieNode* root;
    int count = 0;
    void dfsCount(TrieNode* node, int i) { // 第i个字母
        if(!node) {
            return;
        }
        bool hasChild = false;
        for(int j = 0; j < 26; j++) {
            if(node -> childNode[j]) {
                dfsCount(node -> childNode[j], i + 1);
                hasChild = true;
            }
        }
        if(!hasChild && node -> isVal) {
            count += i + 1;
        }
    }
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* p = root;
        for(int i = word.length() - 1; i >= 0; i --) {
            char ch = word[i];
            if (p -> childNode[ch - 'a'] == nullptr) {
                p -> childNode[ch - 'a'] = new TrieNode();
            }
            p = p -> childNode[ch - 'a'];
        }
        p -> isVal = true;
    }
    
    int minimumLengthEncoding() {
        count = 0;
        dfsCount(root, 0);
        return count;
    }
};
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        Trie tree;
        for(string& word: words) {
            tree.insert(word);
        }
        return tree.minimumLengthEncoding();
    }
};
