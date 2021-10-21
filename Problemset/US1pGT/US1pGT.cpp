
// @Title: 神奇的字典 (神奇的字典)
// @Author: rubychen0611
// @Date: 2021-10-20 19:56:25
// @Runtime: 72 ms
// @Memory: 93.5 MB

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
public:
    /** Initialize your data structure here. */
    TrieNode* root;
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
    
    bool dfsSearch(TrieNode* node, string& searchWord, int i, bool edit) {
        if(!node) {
            return false;
        }
        if(i == searchWord.size()) {
            if(edit == true && node -> isVal) {
                return true;
            }
            else return false;
        }

        if (edit == false) { // 前面未修改过
            for(int j = 0; j < 26; j++) { // 修改这个
                if(searchWord[i] != 'a' + j) {
                    if (dfsSearch(node -> childNode[j], searchWord, i + 1, true)) {
                        return true;
                    }
                }
            }
            // 不修改这个
            if (dfsSearch(node -> childNode[searchWord[i] - 'a'], searchWord, i + 1, false)) {
                return true;
            }
        } else { // 前面已修改过
            if (dfsSearch(node -> childNode[searchWord[i] - 'a'], searchWord, i + 1, edit)) {
                return true;
            }
        }
        return false;
    }
};

class MagicDictionary {
private:
    Trie* tree;
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
        tree = new Trie();
    }
    
    void buildDict(vector<string> dictionary) {
        for(string & word: dictionary) {
            tree -> insert(word);
        }
    }
    
    bool search(string searchWord) {
        return tree -> dfsSearch(tree -> root , searchWord, 0, false);
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */
