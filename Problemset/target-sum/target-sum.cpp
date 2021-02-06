
// @Title: 目标和 (Target Sum)
// @Author: rubychen0611
// @Date: 2021-02-06 12:38:28
// @Runtime: 96 ms
// @Memory: 21.1 MB

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = 0;
        int n = nums.size();
        for(int x: nums)
        {
            sum += abs(x);
        }
        if (abs(S) > sum)
            return 0;
        vector<vector<int>> dp(n, vector<int> (2 * sum + 1,0));
        dp[0][nums[0] + sum] = 1;
        dp[0][-nums[0] + sum] += 1;
        for(int i = 1; i < n; i++)
        {
            for(int j = -sum; j <= sum; j++)
            {
                if(j - nums[i] + sum >= 0)
                    dp[i][j + sum] += dp[i - 1][j - nums[i] + sum];
                if (j + nums[i] <= sum)
                    dp[i][j + sum] += dp[i - 1][j + nums[i] + sum];
                //cout << dp[i][j+sum] << " ";
            }
           // cout <<endl;
        }
        return dp[n-1][S+sum];
    }
};

