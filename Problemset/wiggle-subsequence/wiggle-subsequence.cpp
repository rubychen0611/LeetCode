
// @Title: 摆动序列 (Wiggle Subsequence)
// @Author: rubychen0611
// @Date: 2021-02-05 21:36:59
// @Runtime: 0 ms
// @Memory: 6.8 MB

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1)
            return n;
        int ans = 1;
        int pre_diff = 0;
        int cur_diff = 0;
        for(int i = 1; i < n; i++)
        {
            cur_diff = nums[i] - nums[i-1];
            if ((cur_diff > 0 && pre_diff <= 0) || (cur_diff < 0 && pre_diff >= 0) )
            {
                ans ++;
                pre_diff = cur_diff;
            }
        }
        return ans;
    }
};

