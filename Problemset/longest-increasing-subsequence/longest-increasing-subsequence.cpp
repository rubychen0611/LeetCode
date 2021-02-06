
// @Title: 最长递增子序列 (Longest Increasing Subsequence)
// @Author: rubychen0611
// @Date: 2021-01-27 13:38:35
// @Runtime: 280 ms
// @Memory: 10.3 MB

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(), ans = 1;
        vector<int> dp(n);
        dp[0] = 1;
        for (int i = 1; i < n; i++)
        {
            int max = 0;
            for (int j = 0; j < i; j++)
            {
                if(nums[j] < nums[i])
                {
                    if(dp[j] > max)
                        max = dp[j];
                }
            }
            dp[i] = max + 1;
            if(dp[i] > ans)
                ans = dp[i];
        }
        return ans;
    }
};

