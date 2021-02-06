
// @Title: 整数拆分 (Integer Break)
// @Author: rubychen0611
// @Date: 2021-02-03 15:14:29
// @Runtime: 0 ms
// @Memory: 6.1 MB

class Solution {
private:
    int max(int a, int b)
    {
        return a > b ? a : b;
    }
public:
    int integerBreak(int n) {
        if (n == 2)
            return 1;
        if (n == 3)
            return 2;
        vector<int> dp(n+1, 0);
        dp[2] = 2;
        dp[3] = 3;
        for (int i = 4; i <= n; i++)
        {
            for (int j = 2; j <= i / 2; j++)
            {
                dp[i] = max(dp[i], dp[j] * dp[i-j]);
            }
        }
        return dp[n];
    }
};

