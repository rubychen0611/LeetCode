
// @Title: 非递减数列 (Non-decreasing Array)
// @Author: rubychen0611
// @Date: 2021-01-25 15:11:53
// @Runtime: 36 ms
// @Memory: 26.4 MB

class Solution {
public:
    bool checkPossibility(vector<int>& nums)
    {
        bool flag = false;
        for(int i = 0; i < nums.size()-1; i++)
        {
            if(nums[i+1] < nums[i])
            {
                if (flag)
                    return false;
                if(i + 1 == nums.size()-1 || i == 0 || nums[i+1] >= nums[i-1] || (i+2 < nums.size() && nums[i+2] >= nums[i]))
                    flag = true;
                else
                    return false;
            }
        }
        return true;
    }
};

