
// @Title: 正则表达式匹配 (Regular Expression Matching)
// @Author: rubychen0611
// @Date: 2021-02-02 23:39:25
// @Runtime: 4 ms
// @Memory: 6.9 MB

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        s = "0" + s;
        p = "0" + p;
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for(int i = 0; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if (i > 0 && dp[i-1][j-1])
                {
                    if (s[i] == p[j] || p[j] == '.')
                    {
                        dp[i][j] = true;
                        continue;
                    }
                }

                if (p[j] == '*')
                {
                     if (dp[i][j-1] || (j >= 2 && dp[i][j-2]) || (i > 0 && dp[i-1][j] && (s[i]==p[j-1] || p[j-1] == '.')))
                         dp[i][j] = true;
                }
                //cout << i << " " << j << " " << dp[i][j] <<endl;
            }
        }
        return dp[m][n];
    }
};

