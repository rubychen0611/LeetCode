
// @Title: 实现前缀树 (实现前缀树)
// @Author: rubychen0611
// @Date: 2021-10-20 11:41:46
// @Runtime: 36 ms
// @Memory: 43.9 MB

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
class Trie {
private:
    TrieNode* root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* p = root;
        for(char ch: word) {
            if (p -> childNode[ch - 'a'] == nullptr) {
                p -> childNode[ch - 'a'] = new TrieNode();
            }
            p = p -> childNode[ch - 'a'];
        }
        p -> isVal = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* p = root;
        for(char ch: word) {
            if (p -> childNode[ch - 'a'] == nullptr) {
               return false;
            }
            p = p -> childNode[ch - 'a'];
        }
        return p -> isVal;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* p = root;
        for(char ch: prefix) {
            if (p -> childNode[ch - 'a'] == nullptr) {
               return false;
            }
            p = p -> childNode[ch - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
