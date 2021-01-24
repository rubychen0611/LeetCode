
// @Title: 寻找重复数 (Find the Duplicate Number)
// @Author: rubychen0611
// @Date: 2021-01-22 20:33:39
// @Runtime: 16 ms
// @Memory: 10.7 MB

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++)
        {
            int pos = abs(nums[i]) - 1;
            if (nums[pos] < 0)
                return abs(nums[i]);
            else
                nums[pos] = - nums[pos];
        }
        return -1;
    }
};

