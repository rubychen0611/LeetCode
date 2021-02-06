
// @Title: 零钱兑换 (Coin Change)
// @Author: rubychen0611
// @Date: 2021-02-02 16:15:23
// @Runtime: 112 ms
// @Memory: 13.5 MB

class Solution {
private:
    int min(int a, int b)
    {
        return a < b ? a : b;
    }
public:
    int coinChange(vector<int>& coins, int amount)
    {
        int n = coins.size();
        vector<int> dp(amount + 1, -1);
        dp[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= amount; j++)
            {
                if(j >= coins[i-1] && dp[j-coins[i-1]] != -1)
                {
                    if (dp[j] == -1)
                        dp[j] = dp[j-coins[i-1]] + 1;
                    else
                        dp[j] = min(dp[j], dp[j-coins[i-1]] + 1);
                }
            }
        }
        return dp[amount];
    }
};

