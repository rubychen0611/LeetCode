
// @Title: 词典中最长的单词 (Longest Word in Dictionary)
// @Author: rubychen0611
// @Date: 2021-02-12 13:39:23
// @Runtime: 56 ms
// @Memory: 30.6 MB

struct TrieNode
{
    TrieNode* childNode[26];
    bool isVal;		// 此节点的前缀是否是一个单词
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
    void dfs(TrieNode* root, int& max_len, string &ans, string cur_word)
    {
        if(!root)
            return;
        if(!root -> isVal)
            return;
        if(cur_word.length() > max_len)
        {
            ans = cur_word;
            max_len = cur_word.length();
        }
        for(int i = 0; i < 26; i++)
        {
            if(root -> childNode[i])
            {
                dfs(root -> childNode[i], max_len, ans, cur_word + (char)(i + 'a'));
            }
        }
    }
    string longestWord()
    {
        root -> isVal = true;
        int max_len = 0;
        string ans = "";
        string cur_word = "";
        dfs(root, max_len, ans, cur_word);
        return ans;
    }
};
class Solution {
public:
    string longestWord(vector<string>& words) {
        Trie trie;
        for(const string& word: words)
            trie.insert(word);
        return trie.longestWord();
    }
};
