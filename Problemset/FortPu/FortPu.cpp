
// @Title: 插入、删除和随机访问都是 O(1) 的容器 (插入、删除和随机访问都是 O(1) 的容器)
// @Author: rubychen0611
// @Date: 2021-10-09 20:14:21
// @Runtime: 252 ms
// @Memory: 94.7 MB

class RandomizedSet {
private:
    vector<int> array;
    unordered_map<int, int> numToLocation;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(numToLocation.find(val) != numToLocation.end()) {
            return false;
        }
        array.push_back(val);
        numToLocation.insert(pair<int,int>(val, array.size() - 1));
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(numToLocation.find(val) == numToLocation.end()) {
            return false;
        }
        int location = numToLocation[val];
        array[location] = array.back();
        numToLocation[array.back()] = location;
        array.pop_back();
        numToLocation.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int r = rand() % array.size();
        return array[r];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
