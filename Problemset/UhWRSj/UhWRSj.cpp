
// @Title: 替换单词 (替换单词)
// @Author: rubychen0611
// @Date: 2021-10-20 19:20:07
// @Runtime: 40 ms
// @Memory: 50 MB

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
    
    string searchWordRoot(string word) {
        TrieNode* p = root;
        for(int i = 0; i < word.length(); i++) {
            char ch = word[i];
            if (p -> childNode[ch - 'a'] == nullptr) {
               return word;
            }
            p = p -> childNode[ch - 'a'];
            if(p -> isVal) {
                return word.substr(0, i + 1);
            }
        }
        return word;
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie tree;
        for(string& prefix: dictionary) {
            tree.insert(prefix);
        }
        string new_sentence = "";
        string word = "";
        for(char ch: sentence) {
            if (ch == ' ') {
                new_sentence += tree.searchWordRoot(word) + " ";
                word = "";
            }
            else {
                word += ch;
            }
        }
        new_sentence += tree.searchWordRoot(word);
        return new_sentence;
    }
};
