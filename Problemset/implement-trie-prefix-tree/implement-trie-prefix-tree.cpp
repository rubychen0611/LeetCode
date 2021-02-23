
// @Title: 实现 Trie (前缀树) (Implement Trie (Prefix Tree))
// @Author: rubychen0611
// @Date: 2021-02-12 13:20:43
// @Runtime: 56 ms
// @Memory: 43.8 MB

struct TrieNode
{
    TrieNode* childNode[26];
    bool isVal;
    TrieNode():isVal(false)
    {
        for(int i = 0; i < 26; i++)
            childNode[i] = nullptr;
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
        for(int i = 0; i < word.length(); i++)
        {
            if(!p -> childNode[word[i] - 'a'])
                p -> childNode[word[i] - 'a'] = new TrieNode();
            p = p -> childNode[word[i] - 'a'];
        }
        p -> isVal = true; // 是一个词
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* p = root;
        for(int i = 0; i < word.length(); i++)
        {
            if(p == nullptr)
                return false;
            p = p -> childNode[word[i] - 'a'];
        }
        if (!p || !(p -> isVal))
            return false;
        return true;

    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* p = root;
        for(int i = 0; i < prefix.length(); i++)
        {
            if(p == nullptr)
                return false;
            p = p -> childNode[prefix[i] - 'a'];
        }
        return p != nullptr;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
