
// @Title: 分割等和子集 (Partition Equal Subset Sum)
// @Author: rubychen0611
// @Date: 2021-02-18 10:18:22
// @Runtime: 188 ms
// @Memory: 8.9 MB

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(const int & x: nums)
        {
            sum += x;
        }
        if (sum % 2 == 1)
            return false;
        sum /= 2;
        int n = nums.size();
        vector<bool>dp (sum + 1, false);
        dp[0] = true;
        for(int i = 1; i <= n; i++)
        {
            for(int j = sum; j >= 1; j--)
            {
                if(j >= nums[i-1])
                    dp[j] = dp[j] || dp[j-nums[i-1]];
            }
        }
        return dp[sum];
    }
};
