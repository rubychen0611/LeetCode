
// @Title: 最大子序和 (Maximum Subarray)
// @Author: rubychen0611
// @Date: 2021-02-09 23:33:57
// @Runtime: 12 ms
// @Memory: 12.9 MB

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        int ans = nums[0];
        for(int i = 0; i < n; i++)
        {
            dp[i] = nums[i];
            if(i > 0)
                dp[i] = max(dp[i], dp[i-1] + nums[i]);
            if (ans < dp[i])
                ans = dp[i];
        }
        return ans;
    }
};
