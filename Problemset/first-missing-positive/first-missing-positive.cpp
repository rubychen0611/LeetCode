
// @Title: 缺失的第一个正数 (First Missing Positive)
// @Author: rubychen0611
// @Date: 2021-02-17 14:47:39
// @Runtime: 0 ms
// @Memory: 9.5 MB

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            while(nums[i] >= 1 && nums[i] <= n && nums[i] != i + 1 && nums[nums[i]- 1] != nums[i])
            {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        for(int i = 0; i < n; i++)
        {
            if(i+1 != nums[i])
                return i+1;
        }
        return n+1;
    }
};
