
// @Title: 爬楼梯的最少成本 (爬楼梯的最少成本)
// @Author: rubychen0611
// @Date: 2021-10-17 19:56:22
// @Runtime: 8 ms
// @Memory: 13.4 MB

class Solution {
private:
    int min(int a, int b) {
        return a < b ? a : b;
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        dp[1] = 0;
        for(int i = 2; i <= n; i++) {
            dp[i] = min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2]);
        }
        return dp[n];
    }
    
};
