
// @Title: 两数之和 (Two Sum)
// @Author: rubychen0611
// @Date: 2021-01-22 13:19:12
// @Runtime: 0 ms
// @Memory: 8.6 MB

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashmap;
        for (int i = 0; i < nums.size(); i++) {

            auto it = hashmap.find(target - nums[i]);
            if (it != hashmap.end()) {
                return vector<int>{it->second, i};
            }
            hashmap[nums[i]] = i;
        }
        return vector<int>(2);
    }
};

