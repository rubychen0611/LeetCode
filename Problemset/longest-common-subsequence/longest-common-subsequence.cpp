
// @Title: 最长公共子序列 (Longest Common Subsequence)
// @Author: rubychen0611
// @Date: 2021-01-27 14:15:45
// @Runtime: 32 ms
// @Memory: 12.7 MB

class Solution {
private:
    int max(int a, int b)
    {
        return a > b ? a : b;
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length(), n = text2.length();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(text1[i] == text2[j])
                {
                    if (i == 0 || j == 0)
                        dp[i][j] = 1;
                    else
                        dp[i][j] = dp[i-1][j-1] + 1;
                }
                else if (i > 0 && j >0)
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                else if(i > 0)
                    dp[i][j] =dp[i-1][j];
                else if (j > 0)
                    dp[i][j] =dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};

