
// @Title: 两数之和 (Two Sum)
// @Author: rubychen0611
// @Date: 2020-10-24 11:20:50
// @Runtime: 580 ms
// @Memory: 9 MB

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res = {0, 0};
        int len = nums.size();
        for (int i = 0; i < len - 1; i++)
            for (int j = i + 1; j < len; j++)
                if (nums[i] + nums[j] == target)
                {
                    res[0] = i;
                    res[1] = j;
                    return res;
                }
        return res;
    }
};

