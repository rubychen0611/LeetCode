
// @Title: 设计哈希集合 (Design HashSet)
// @Author: rubychen0611
// @Date: 2021-01-22 14:22:52
// @Runtime: 136 ms
// @Memory: 39.8 MB

class MyHashSet {
private:
    vector<list<int>> hash_table;
    const int size;
    int hash_function(int key)
    {
        return key % size;
    }
public:
    /** Initialize your data structure here. */
    MyHashSet():size(100){
        hash_table.resize(size);
    }
    
    void add(int key) {
        if (!contains(key))
            hash_table[hash_function(key)].push_back(key);
    }
    
    void remove(int key) {
        int hash_idx = hash_function(key);
        list<int> &l = hash_table[hash_idx];
        if (l.empty())
            return;
        list<int> ::iterator it = find(l.begin(), l.end(), key);
        if( it != l.end())
        {
            l.erase(it);
        }
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int hash_idx = hash_function(key);
        list<int> &l = hash_table[hash_idx];
        if (l.empty())
            return false;
        list<int> ::iterator it = find(l.begin(), l.end(), key);
        return it != l.end();
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */

