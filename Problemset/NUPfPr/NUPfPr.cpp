
// @Title: 分割等和子集 (分割等和子集)
// @Author: rubychen0611
// @Date: 2021-10-17 23:19:31
// @Runtime: 92 ms
// @Memory: 8.9 MB

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        //f(n, s) = f(n-1, s) || f(n-1, s-nums[i]) 
        int sum = 0;
        int n = nums.size();
        for(int x: nums) {
            sum += x;
        }
        if(sum % 2 == 1) {
            return false;
        }
        sum /= 2;
        vector<bool> dp(sum + 1, false);
        dp[0] = true;
        for(int i = 0; i < n; i++) {
            for(int j = sum; j >= 0; j--) {
                if(j >= nums[i] && !dp[j] && dp[j - nums[i]]) {
                    dp[j] = true;
                    //cout << i << " " <<j <<endl;
                }
            }
        }
        return dp[sum] == true;
    }
};
