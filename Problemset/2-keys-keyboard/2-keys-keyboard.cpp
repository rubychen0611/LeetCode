
// @Title: 只有两个键的键盘 (2 Keys Keyboard)
// @Author: rubychen0611
// @Date: 2021-02-02 22:17:56
// @Runtime: 4 ms
// @Memory: 6.4 MB

class Solution {
private:
    int min(int a, int b)
    {
        return a < b ? a : b;
    }
    int min(int a, int b, int c)
    {
        return min(min(a, b), c);
    }
public:
    int minSteps(int n)
    {
        if (n == 1)
            return 0;
        vector<int> dp(n + 1);
        dp[1] = 0;
        for(int i = 2; i <= n; i++)
        {
            dp[i] = i;
            for (int j = 2; j <= sqrt(i); j++)
            {
                if (i % j == 0)
                {
                    dp[i] = min(dp[i], dp[j] + i / j, dp[i / j] + j);
                }
            }
        }
        return dp[n];
    }
};

