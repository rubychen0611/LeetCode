
// @Title: 数组中重复的数字 (数组中重复的数字 LCOF)
// @Author: rubychen0611
// @Date: 2021-02-11 19:51:22
// @Runtime: 36 ms
// @Memory: 22.3 MB

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++)
        {
            while(nums[i] != i)
            {
                if(nums[nums[i]] != nums[i])
                    swap(nums[nums[i]], nums[i]);
                else return nums[i];
            }
        }
        return -1;
    }
};
