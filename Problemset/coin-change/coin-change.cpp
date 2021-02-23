
// @Title: 零钱兑换 (Coin Change)
// @Author: rubychen0611
// @Date: 2021-02-18 10:39:12
// @Runtime: 116 ms
// @Memory: 13.7 MB

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0)
            return 0;
        int n = coins.size();
        vector<int> dp (amount+1, INT_MAX -1);
        dp[0] = 0;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 0; j <= amount; j++)
            {
                if(j >= coins[i-1])
                    dp[j] = min(dp[j], dp[j - coins[i-1]] + 1);
            }
        }
        if(dp[amount] == INT_MAX - 1)
            return -1;
        return dp[amount];
    }
};
