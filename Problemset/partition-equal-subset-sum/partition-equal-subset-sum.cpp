
// @Title: 分割等和子集 (Partition Equal Subset Sum)
// @Author: rubychen0611
// @Date: 2021-02-02 14:43:03
// @Runtime: 168 ms
// @Memory: 8.9 MB

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0, max = 0;
        for(const int & x: nums)
        {
            sum += x;
            if (x > max)
                max = 0;
        }
        if (sum % 2 == 1)
            return false;
        sum /= 2;
        int n = nums.size();
        vector<bool> dp(sum + 1, false);
        sort(nums.begin(), nums.end());
        dp[0] = true;
        for(int i = 0; i < n; i++)
        {
            if (nums[i] > sum)
                break;
            for(int s = sum; s >= 1; s--)
            {
                if (s >= nums[i])
                    dp[s] = dp[s] || dp[s - nums[i]];
            }
            if (dp[sum])
                return true;
        }
        return false;
    }
};

