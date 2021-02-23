
// @Title: 剪绳子 (剪绳子  LCOF)
// @Author: rubychen0611
// @Date: 2021-02-18 13:36:27
// @Runtime: 0 ms
// @Memory: 6.2 MB

class Solution {
public:
    int cuttingRope(int n) {
        vector<int> dp(1 + n, 0);
        if (n == 2)
            return 1;
        if  (n == 3)
            return 2;
        dp[2] = 2;
        dp[3] = 3;
        for(int i = 4; i <= n; i++)
        {
            dp[i] = 0;
            for(int j = 1; j <= i / 2; j++)
            {
                dp[i] = max(dp[i], dp[j] * dp[i-j]);
            }
        }
        return dp[n];
    }
};
