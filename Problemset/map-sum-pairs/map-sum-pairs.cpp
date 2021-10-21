
// @Title: 键值映射 (Map Sum Pairs)
// @Author: rubychen0611
// @Date: 2021-10-20 20:37:10
// @Runtime: 0 ms
// @Memory: 7.9 MB

struct TrieNode {
    TrieNode* childNode[26];
    bool isVal;
    int value; // 增加一个value
    TrieNode () {
        isVal = false;
        value = -1;
        for(int i = 0; i < 26; i++) {
            childNode[i] = nullptr;
        }
    }
};
class Trie {
private:
    TrieNode* root;
    int sum;

    TrieNode* getStartNode(string prefix) {
        TrieNode* p = root;
        for(char ch: prefix) {
            if (p -> childNode[ch - 'a'] == nullptr) {
               return nullptr;
            }
            p = p -> childNode[ch - 'a'];
        }
        return p;
    }

    void dfsSum(TrieNode* root) {
        if(!root) {
            return;
        }
        if(root -> isVal) {
            sum += root -> value;
        }
        for(int i = 0; i < 26; i++) {
            dfsSum(root -> childNode[i]);
        }
    }
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word, int val) {
        TrieNode* p = root;
        for(char ch: word) {
            if (p -> childNode[ch - 'a'] == nullptr) {
                p -> childNode[ch - 'a'] = new TrieNode();
            }
            p = p -> childNode[ch - 'a'];
        }
        p -> isVal = true;
        p -> value = val;
    }
    
    int getSum(string prefix) {
        TrieNode* startNode = getStartNode(prefix);
        sum = 0;
        dfsSum(startNode);
        return sum;
    }
};

class MapSum {
private:
    Trie* tree;
public:
    /** Initialize your data structure here. */
    MapSum() {
        tree = new Trie();
    }
    
    void insert(string key, int val) {
        tree -> insert(key, val);
    }
    
    int sum(string prefix) {
        return tree -> getSum(prefix);
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
