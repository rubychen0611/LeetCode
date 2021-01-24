
// @Title: 设计哈希映射 (Design HashMap)
// @Author: rubychen0611
// @Date: 2021-01-22 14:42:18
// @Runtime: 116 ms
// @Memory: 41 MB

struct Pair
{
    int key, value;
    Pair(int k, int v): key(k), value(v){}
};
class MyHashMap {
private:
    vector<list<Pair>> hash_table;
    const int size;
    int hash_function(int key)
    {
        return key % size;
    }
public:
    /** Initialize your data structure here. */
    MyHashMap():size(100){
        hash_table.resize(size);
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int hash_idx = hash_function(key);
        list<Pair>& l = hash_table[hash_idx];
        if(l.empty()) {
            l.push_back(Pair(key, value));
            return;
        }
        for(list<Pair>::iterator it = l.begin(); it != l.end(); it++)
        {
            if (it -> key == key)
            {
                it -> value = value;
                return;
            }
        }
        l.push_back(Pair(key, value));
        return;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int hash_idx = hash_function(key);
        list<Pair>& l = hash_table[hash_idx];
        if(l.empty())
            return -1;
        for(list<Pair>::iterator it = l.begin(); it != l.end(); it++)
        {
            if (it -> key == key)
            {
                return it -> value;
            }
        }
        return -1;

    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int hash_idx = hash_function(key);
        list<Pair>& l = hash_table[hash_idx];
        if(l.empty())
            return;
        for(list<Pair>::iterator it = l.begin(); it != l.end(); it++)
        {
            if (it -> key == key)
            {
                l.erase(it);
                return;
            }
        }
        return;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

