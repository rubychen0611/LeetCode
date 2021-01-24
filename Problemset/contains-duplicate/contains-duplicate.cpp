
// @Title: 存在重复元素 (Contains Duplicate)
// @Author: rubychen0611
// @Date: 2021-01-22 17:55:13
// @Runtime: 32 ms
// @Memory: 19.5 MB

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> hash_set;
        for (int x: nums)
        {
            if (hash_set.find(x) != hash_set.end())
                return true;
            hash_set.insert(x);
        }
        return false;
    }
};

