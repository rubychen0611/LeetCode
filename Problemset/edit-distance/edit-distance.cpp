
// @Title: 编辑距离 (Edit Distance)
// @Author: rubychen0611
// @Date: 2021-02-02 20:14:37
// @Runtime: 16 ms
// @Memory: 8.8 MB

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
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int> (n + 1, 0));
        for (int i = 0; i <= m; i ++)
        {
            for(int j = 0; j <= n; j++)
            {
                if (i == 0)
                    dp[i][j] = j;
                else if (j == 0)
                    dp[i][j] = i;
                else
                    dp[i][j] = min(dp[i-1][j] + 1, dp[i][j-1] + 1, dp[i-1][j-1] + (int)(word1[i-1] != word2[j-1]));
            }
        }
        return dp[m][n];
    }
};

