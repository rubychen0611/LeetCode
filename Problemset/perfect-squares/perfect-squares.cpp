
// @Title: 完全平方数 (Perfect Squares)
// @Author: rubychen0611
// @Date: 2021-01-27 01:20:24
// @Runtime: 204 ms
// @Memory: 8.9 MB

class Solution {
private:
    int min(int a, int b)
    {
        return a < b ? a : b;
    }
public:
    int numSquares(int n) {
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j * j <= i; j++)
            {
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }
        return dp[n];
    }
};

