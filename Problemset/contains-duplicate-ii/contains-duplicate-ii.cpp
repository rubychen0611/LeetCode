
// @Title: 存在重复元素 II (Contains Duplicate II)
// @Author: rubychen0611
// @Date: 2021-01-23 14:23:06
// @Runtime: 28 ms
// @Memory: 16.1 MB

//struct Info
//{
//    int last;
//    int cur_min;
//    Info(int idx, int k)
//    {
//        last = idx;
//        cur_min = k + 1;
//    }
//};

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> hash_map;   // 数字，上次出现的位置
        for(int i = 0; i < nums.size(); i++)
        {
            int x = nums[i];
            if(hash_map.find(x) == hash_map.end())
                hash_map[x] = i;
            else if (i - hash_map[x] <= k)
                return true;
            else
                hash_map[x] = i;
        }
        return false;
    }
};

